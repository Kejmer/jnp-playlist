#include "Media.h"

const string Media::audioMeta[2] = {"artist","title"};
const string Media::videoMeta[2] = {"year","title"};

void Media::play() const
{
  displayType();
  displayMetadata();
  displayContent();
}

void Media::displayMetadata() const
{
  cout << "[";
  for (unsigned i = 0; i < metadata.size(); i++) {
    if (i > 0) cout << ", ";
    cout << metadata[i];
  }
  cout << "]";
}

void Media::displayContent() const
{
  cout << content;
}

void Media::displayType() const
{
  cout << mediaType;
}

Media::Media(std::string &content)
{
  mediaType = "ASSD";
  this->content = content;// czemu tu bylo "ASXX"
  cout << "TEST1 " << content << endl;
  cout << "TEST2 " << this->content << endl;

  // mediaType = content;
  // metadata.push_back(content);
  // this->content = content;
}
