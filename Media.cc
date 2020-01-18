#include <iterator>
#include "Media.h"

const std::list<std::string> Media::AudioStrategy::audioMeta = {"artist","title"};
const std::list<std::string> Media::VideoStrategy::videoMeta = {"year","title"};

const std::regex Media::audioPattern = regex("audio((?:\\|[a-z]+:[A-z\\d !,]*)*)\\|([A-z\\d ,.!?':;-]*)");
const std::regex Media::videoPattern = regex("video((?:\\|[a-z]+:[A-z\\d !,]*)*)\\|([A-z\\d ,.!?':;-]*)");

Media::Media(std::string &content)
{
  std::smatch m;

  if (std::regex_match(content, m, audioPattern)) {
    std::cout << "PASUJE TUTAJ\n";
    this->strategy = AudioStrategy(m.str(1), m.str(2));
  } else
  if (std::regex_match(content, m, videoPattern)) {
    this->strategy = VideoStrategy(m.str(1), m.str(2));
  } else {
    throw CorruptionException();
  }
}

std::string Media::AbsStrategy::findMeta(std::string &dataType)
{
  const std::regex pattern("(?<=\\|" + dataType + ":)(.*?)");
  std::smatch m;
  std::regex_search(dataType, m, pattern);
  if (m.empty()) throw BadMetadataException(dataType);
  return m.suffix().str();
}

Media::AudioStrategy::AudioStrategy(std::list<std::string> &rawMeta, std::string &rawContent)
{
  this->content = rawContent;
  processMeta(rawMeta, audioMeta);
}

Media::AudioStrategy::AudioStrategy(std::list<std::string> &rawMeta, std::string &rawContent)
{
  this->content = ROT13::encode(rawContent);
  processMeta(rawMeta, videoMeta);
}

void Media::AbsStrategy::processMeta(std::string &rawMeta, std::list<std::string> &metaList)
{
  std::string result = "[";
  bool notFirst = false;
  for (auto type : metaList) {
    if (notFirst) result += ", "; else notFirst = true;
    result += findMeta(type);
  }
  result += "]";
}

void Media::AbsStrategy::perform()
{
  std::cout << " ";
  displayType();
  std::cout << " " << metadata << ": " << content;
}

void Media::AudioStrategy::displayType()
{
  std::cout << "Song";
}

void Media::VideoStrategy::displayType()
{
  std::cout << "Movie";
}