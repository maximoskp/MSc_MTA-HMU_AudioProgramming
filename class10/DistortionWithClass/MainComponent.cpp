#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }

    c = ClippingDistortion();

    addAndMakeVisible(preamp_slider);
    preamp_slider.setRange(1.0, 10.0, 0.1);
    preamp_slider.setValue(2.0);
    preamp_slider.onValueChange = [this] {
        juce::Logger::writeToLog("preamp: " + juce::String(preamp_slider.getValue()));
        c.set_preamp_value( preamp_slider.getValue() );
    };

    addAndMakeVisible(clip_slider);
    clip_slider.setRange(0.01, 1.0, 0.01);
    clip_slider.setValue(0.3);
    clip_slider.onValueChange = [this] {
        juce::Logger::writeToLog("clip_slider: " + juce::String(clip_slider.getValue()));
        c.set_clip_value( clip_slider.getValue() );
    };

    addAndMakeVisible(poweramp_slider);
    poweramp_slider.setRange(1.0, 10.0, 0.1);
    poweramp_slider.setValue(2.0);
    poweramp_slider.onValueChange = [this] {
        juce::Logger::writeToLog("poweramp_slider: " + juce::String(poweramp_slider.getValue()));
        c.set_poweramp_value( poweramp_slider.getValue() );
    };

}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
    juce::Logger::writeToLog("sampleRate: " + juce::String(sampleRate));
    juce::Logger::writeToLog("samplesPerBlockExpected: " + juce::String(samplesPerBlockExpected));
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    // bufferToFill.clearActiveBufferRegion();
    const float* mic0_buffer = bufferToFill.buffer->getReadPointer(0, bufferToFill.startSample);
    float* speaker0_buffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    float* speaker1_buffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
    for (int i = 0; i < bufferToFill.numSamples; i++) {
        speaker0_buffer[i] = c.process_sample( mic0_buffer[i] );
        speaker1_buffer[i] = c.process_sample( mic0_buffer[i]);
    }
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    preamp_slider.setBounds(50, 100, 300, 50);
    clip_slider.setBounds(50, 200, 300, 50);
    poweramp_slider.setBounds(50, 300, 300, 50);
}
