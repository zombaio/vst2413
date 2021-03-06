#ifndef __Vst2413p__
#define __Vst2413p__

#include "audioeffectx.h"
#include "SynthDriver.h"

class Vst2413p : public AudioEffectX {
public:
    static const unsigned long kUniqueId = 'dAzx';

    Vst2413p(audioMasterCallback audioMaster);

	virtual void processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames);
	virtual VstInt32 processEvents(VstEvents* events);
    
	virtual void setParameter(VstInt32 index, float value);
	virtual float getParameter(VstInt32 index);
	virtual void getParameterLabel(VstInt32 index, char* label);
	virtual void getParameterDisplay(VstInt32 index, char* text);
	virtual void getParameterName(VstInt32 index, char* text);
	
	virtual void setSampleRate(float sampleRate);
	virtual bool getOutputProperties(VstInt32 index, VstPinProperties* properties);
    
	virtual bool getEffectName(char* name);
	virtual bool getVendorString(char* text);
	virtual bool getProductString(char* text);
	virtual VstInt32 getVendorVersion();
	virtual VstInt32 canDo(char* text);
    
	virtual VstInt32 getNumMidiInputChannels();
	virtual VstInt32 getNumMidiOutputChannels();

private:
    SynthDriver driver_;
    float instrumentParameter_;
};

#endif
