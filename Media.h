#ifndef MEDIA_H
#define MEDIA_H

#include <list>
#include <regex>
#include <vector>
#include "Playable.h"
#include "PlayerException.h"

class AbsStrategy
{
private:
  std::string findMeta(std::string rawMeta, std::string &dataType);
protected:
  std::string metadata;
  std::string content;
  void processMeta(std::string &rawMeta, const std::list<std::string> &metaList);
  virtual void displayType() const = 0;
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

class Media : public Playable
{
private:

  static const std::regex audioPattern;
  static const std::regex videoPattern;

    std::shared_ptr<AbsStrategy> strategy;

public:

  Media(std::string &content);
  ~Media() = default;

  void play() const override;

};

#endif /* MEDIA_H */
