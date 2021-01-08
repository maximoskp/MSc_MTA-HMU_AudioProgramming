/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
// https://stackoverflow.com/questions/17448014/how-to-use-c-code-in-c
#ifdef __cplusplus
extern "C"
{
#endif

#include "Yin.h"

#ifdef __cplusplus
}
#endif

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent, public Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    void audioFileMenuChanged();
    void playAudioFile();

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    
    // screen size
    int screen_width;
    int screen_height;
    
    // Yin variables
    Yin yin;
    float pitch;
    int buffer_length;
    int sample_rate;
    int bit_depth;
    int16_t *buffer;
    
    // circular buffer sent to Yin for computation
    int16_t *circ_tmp_buffer;
    int16_t *circ_buffer;
    int circ_buffer_length;
    int circ_read_idx;
    int circ_write_idx;
    
    // pitch values
    float *pitch_values;
    int pitch_history;
    // plotting area
    float y_min, y_max, x_min, x_max;
    float freq_min, freq_max;
    StringArray note_symbols;
    float *note_freqs;
    StringArray found_pitch_symbols;
    
    // folder with audio files
    const char* main_audio_folder = "Intervals_Licks_recordings";
    
    // labels for showing frequency
    Label freqLabel;
    
    // dropdown menu for selecting audio file
    ComboBox audioFileMenu;
    StringArray audioFiles;
    
    // play button
    TextButton playButton;
    
    // input button
    TextButton inputButton;
    bool micInput = false;
    
    void timerCallback() override{
        repaint();
    };
    
    int freq2midi(float f){
        return 12*log2(f/440.)+69;
    };
    String midi2symbol(int m){
        return note_symbols[ (int)(floor((float)m+0.5))%12 ];
    };
    
    /* Create required classes for playback */
    // Format manager
    AudioFormatManager *audioFormatManager;
    // Format reader
    AudioFormatReader *audioFormatReader;
    // Reader source
    AudioFormatReaderSource *audioFormatReaderSource;
    // Transport source
    AudioTransportSource *audioTransportSource;
    // Source player
    AudioSourcePlayer *audioSourcePlayer;
    // Device manager
    AudioDeviceManager *audioDeviceManager;
    
    // graphics
    // Rectangle graph_background;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
