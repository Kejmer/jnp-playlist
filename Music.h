#ifndef MUSIC_H
#define MUSIC_H

class Music : public Playable
{
public:
  void play() const override;
};

#endif /* MUSIC_H */