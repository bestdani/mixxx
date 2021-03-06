/**
 * @file midioutputhandler.h
 * @author Sean Pappalardo spappalardo@mixxx.org
 * @date Tue 11 Feb 2012
 * @brief Static MIDI output mapping handler
 *
 * This class listens to a control object and sends a midi message based on the
 * value.
 */

#ifndef MIDIOUTPUTHANDLER_H
#define MIDIOUTPUTHANDLER_H

#include "controlobjectslave.h"
#include "controllers/midi/midimessage.h"

class MidiController;

class MidiOutputHandler : QObject {
    Q_OBJECT
  public:
    MidiOutputHandler(MidiController* controller,
                      const MidiOutputMapping& mapping);
    virtual ~MidiOutputHandler();

    bool validate();
    void update();

  public slots:
    void controlChanged(double value);

  private:
    MidiController* m_pController;
    const MidiOutputMapping m_mapping;
    ControlObjectSlave m_cos;
    int m_lastVal;
};

#endif
