#include <iterator>
#include "Media.h"
#include "Encryption.h"

namespace {
  class AbsStrategy
  {
  private:
    std::string findMeta(std::string rawMeta, std::string &dataType);
  protected:
    std::string metadata, content, type;
    void processMeta(std::string &rawMeta, const std::list<std::string> &metaList);
  public:
    std::string perform() const;
  };

  class AudioStrategy : public AbsStrategy
  {
  private:
    static const std::list<std::string> audioMeta;
  public:
    AudioStrategy(std::string &rawMeta, std::string &rawContent);
  };

  class VideoStrategy : public AbsStrategy
  {
  private:
    static const std::list<std::string> videoMeta;
  public:
    VideoStrategy(std::string &rawMeta, std::string &rawContent);
  };

  const std::list<std::string> AudioStrategy::audioMeta = {"artist","title"};
  const std::list<std::string> VideoStrategy::videoMeta = {"title","year"};

  std::string AbsStrategy::findMeta(std::string rawMeta, std::string &dataType)
  {
    const std::regex pattern("[^\\|]*" + dataType + ":([^\\|]*?)(?=\\|)"); //negative lookbehind nie działa std::regex
    std::smatch m;
    std::string result = "|";
    while(std::regex_search(rawMeta, m, pattern)) {
      result = m[1].str();
      rawMeta = m.suffix().str();
    }

    if (result == "|") throw BadMetadataException(dataType);
    return result;
  }

  AudioStrategy::AudioStrategy(std::string &rawMeta, std::string &rawContent)
  {
    this->content = rawContent;
    this->type = "Song";
    processMeta(rawMeta, audioMeta);
  }

  VideoStrategy::VideoStrategy(std::string &rawMeta, std::string &rawContent)
  {
    this->content = ROT13::encode(rawContent);
    this->type = "Movie";
    processMeta(rawMeta, videoMeta);
  }

  void AbsStrategy::processMeta(std::string &rawMeta, const std::list<std::string> &metaList)
  {
    metadata = "[";
    bool notFirst = false;
    for (auto type : metaList) {
      if (notFirst) metadata += ", "; else notFirst = true;
      metadata += findMeta(rawMeta, type);
    }
    metadata += "]";
  }

  std::string AbsStrategy::perform() const
  {
    std::string result = type + " " + metadata + ": " + content;
    return result;
  }
}

const std::regex Media::audioPattern = std::regex("audio((?:\\|[^\\|]*:[^\\|]*)*\\|)([A-z\\d ,.!?':;-]*)");
const std::regex Media::videoPattern = std::regex("video((?:\\|[^\\|]*:[^\\|]*)*\\|)([A-z\\d ,.!?':;-]*)");

Media::Media(std::string &content)
{
  std::smatch m;
  std::string rawMeta, rawContent;
  AbsStrategy *strategy;

  if (std::regex_match(content, m, audioPattern)) {
    rawMeta = m.str(1);
    rawContent = m.str(2);
    strategy = new AudioStrategy(rawMeta, rawContent);
  } else
  if (std::regex_match(content, m, videoPattern)) {
    rawMeta = m.str(1);
    rawContent = m.str(2);
    strategy = new VideoStrategy(rawMeta, rawContent);
  } else {
    throw CorruptionException();
  }
  this->play_contents = strategy->perform();
  delete strategy;
}

void Media::play() const
{
  std::cout << play_contents << std::endl;
}