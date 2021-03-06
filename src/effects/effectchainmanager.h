#ifndef EFFECTCHAINMANAGER_H
#define EFFECTCHAINMANAGER_H

#include <QObject>
#include <QList>
#include <QHash>

#include "configobject.h"
#include "effects/effectchain.h"
#include "effects/effectrack.h"
#include "engine/channelhandle.h"
#include "util/class.h"

class EffectsManager;

// A class for keeping track of all the user's EffectChains. Eventually will
// serialize/deserialize the EffectChains from storage but for Effects v1 we are
// hard-coding the available chains.
class EffectChainManager : public QObject {
    Q_OBJECT
  public:
    EffectChainManager(ConfigObject<ConfigValue>* pConfig,
                       EffectsManager* pEffectsManager);
    virtual ~EffectChainManager();

    void registerChannel(const ChannelHandleAndGroup& handle_group);
    const QSet<ChannelHandleAndGroup>& registeredChannels() const {
        return m_registeredChannels;
    }

    StandardEffectRackPointer addStandardEffectRack();
    StandardEffectRackPointer getStandardEffectRack(int rack);

    EqualizerRackPointer addEqualizerRack();
    EqualizerRackPointer getEqualizerRack(int rack);

    QuickEffectRackPointer addQuickEffectRack();
    QuickEffectRackPointer getQuickEffectRack(int rack);

    EffectRackPointer getEffectRack(const QString& group);

    void addEffectChain(EffectChainPointer pEffectChain);
    void removeEffectChain(EffectChainPointer pEffectChain);

    // To support cycling through effect chains, there is a global ordering of
    // chains. These methods allow you to get the next or previous chain given
    // your current chain.
    // TODO(rryan): Prevent double-loading of a chain into a slot?
    EffectChainPointer getNextEffectChain(EffectChainPointer pEffectChain);
    EffectChainPointer getPrevEffectChain(EffectChainPointer pEffectChain);

    bool saveEffectChains();
    bool loadEffectChains();

  private:
    QString debugString() const {
        return "EffectChainManager";
    }

    ConfigObject<ConfigValue>* m_pConfig;
    EffectsManager* m_pEffectsManager;
    QList<StandardEffectRackPointer> m_standardEffectRacks;
    QList<EqualizerRackPointer> m_equalizerEffectRacks;
    QList<QuickEffectRackPointer> m_quickEffectRacks;
    QHash<QString, EffectRackPointer> m_effectRacksByGroup;
    QList<EffectChainPointer> m_effectChains;
    QSet<ChannelHandleAndGroup> m_registeredChannels;
    DISALLOW_COPY_AND_ASSIGN(EffectChainManager);
};

#endif /* EFFECTCHAINMANAGER_H */
