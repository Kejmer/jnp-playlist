#ifndef MEDIA_H
#define MEDIA_H

#include <list>
#include <regex>
#include <vector>
#include "Playable.h"
#include "PlayerException.h"

class Media : public Playable
{
private:
  class AbsStrategy
  {
  private:
    std::string findMeta(std::string &data);
  protected:
    virtual void displayType() const = 0;
    std::string metadata;
    std::string content;
    void processMeta(std::string &rawMeta, std::list<std::string> &metaList);
  public:
    void perform() const;
  };

  class AudioStrategy : public AbsStrategy
  {
  private:
    static const std::list<std::string> audioMeta;
  protected:
    void displayType() const override;
  public:
    AudioStrategy(std::string &rawMeta, std::string &rawContent);
  };

  class VideoStrategy : public AbsStrategy
  {
  private:
    static const std::list<std::string> videoMeta;
  protected:
    void displayType() const override;
  public:
    VideoStrategy(std::string &rawMeta, std::string &rawContent);
  };

  static const std::regex audioPattern;
  static const std::regex videoPattern;

  AbsStrategy strategy;

public:

  Media(string &content);
  ~Media() = default;

  void play() const override;

};

#endif /* MEDIA_H */
