#include <iterator>
#include "Media.h"
#include "Encryption.h"

const std::list<std::string> AudioStrategy::audioMeta = {"artist","title"};
const std::list<std::string> VideoStrategy::videoMeta = {"title","year"};

const std::regex Media::audioPattern = regex("audio((?:\\|[^\\|]*:[^\\|]*)*\\|)([A-z\\d ,.!?':;-]*)");
const std::regex Media::videoPattern = regex("video((?:\\|[^\\|]*:[^\\|]*)*\\|)([A-z\\d ,.!?':;-]*)");

Media::Media(std::string &content)
{
  std::smatch m;
  std::string rawMeta, rawContent;

  if (std::regex_match(content, m, audioPattern)) {
    rawMeta = m.str(1);
    rawContent = m.str(2);
    this->strategy = new AudioStrategy(rawMeta, rawContent);
  } else
  if (std::regex_match(content, m, videoPattern)) {
    rawMeta = m.str(1);
    rawContent = m.str(2);
    this->strategy = new VideoStrategy(rawMeta, rawContent);
  } else {
    throw CorruptionException();
  }
}

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
  processMeta(rawMeta, audioMeta);
}

VideoStrategy::VideoStrategy(std::string &rawMeta, std::string &rawContent)
{
  this->content = ROT13::encode(rawContent);
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

void AbsStrategy::perform() const
{
  std::cout << " ";
  displayType();
  std::cout << " " << metadata << ": " << content;
}

void AudioStrategy::displayType() const
{
  std::cout << "Song";
}

void VideoStrategy::displayType() const
{
  std::cout << "Movie";
}

void Media::play() const
{
  strategy->perform();
}