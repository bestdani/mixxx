#ifndef MIXER_SAMPLER_H
#define MIXER_SAMPLER_H

#include "mixer/basetrackplayer.h"

class Sampler : public BaseTrackPlayerImpl {
    Q_OBJECT
  public:
    Sampler(QObject* pParent,
            ConfigObject<ConfigValue> *pConfig,
            EngineMaster* pMixingEngine,
            EffectsManager* pEffectsManager,
            EngineChannel::ChannelOrientation defaultOrientation,
            QString group);
    virtual ~Sampler();
};

#endif /* MIXER_SAMPLER_H */
