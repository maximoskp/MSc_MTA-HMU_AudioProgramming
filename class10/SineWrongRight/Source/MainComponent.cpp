#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    
    // __added__ vvv
    frequency = 220.;
    amplitude = 0.5;
    // t = 0.;
    angle = 0.;
    sr = 0.;
    // __added__ ^^^

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
    
    // __added__ vvv
    // initialise UI
    addAndMakeVisible(amp_slider);
    amp_slider.setRange(0., 1., 0.01);
    amp_slider.setValue(0.5);
    amp_slider.onValueChange = [this] { changeAmp(); };

    addAndMakeVisible(freq_slider);
    freq_slider.setRange(20., 1000., 1.);
    freq_slider.setValue(220.);
    freq_slider.onValueChange = [this] { changeFreq(); };
    // __added__ ^^^
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
    sr = (float)sampleRate;
    std::cout << "sr: " << sr << std::endl;
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()
    // __added__ vvv
    if (sr > 0.0) { // make sure that prepareToPlay has been called
        // prepare buffers to write to
        auto* leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
        auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
        for (auto i = 0; i < bufferToFill.numSamples; i++) {
            // instead of preparing a time array, make it on the fly
            // std::cout << "t: " << t << std::endl;
            leftBuffer[i] = amplitude*std::sin(angle);
            rightBuffer[i] = amplitude*std::sin(angle);
            angle += 2.*pi*frequency*(1./sr);
            // wrong way - dependent on t:
//            leftBuffer[i] = amplitude*std::sin(2.*pi*frequency*t/sr);
//            rightBuffer[i] = amplitude*std::sin(2.*pi*frequency*t/sr);
//            t++;
        }
    }
    else { // if not, produce no sound
        bufferToFill.clearActiveBufferRegion();
    }
    // __added__ ^^^
    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    // bufferToFill.clearActiveBufferRegion();
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
    // __added__ vvv
    // normally, we place UI size-related code here, since here their dimensions
    // might need to change
    amp_slider.setBounds(getWidth() / 4. + 10, 100, 3. * getWidth() / 4. - 20, 30);
    freq_slider.setBounds(getWidth() / 4. + 10, 200, 3. * getWidth() / 4. - 20, 30);
    // __added__ ^^^
    
}

void MainComponent::changeAmp(){
    amplitude = amp_slider.getValue();
    std::cout << "amplitude: " << amplitude << std::endl;
}

void MainComponent::changeFreq(){
    frequency = freq_slider.getValue();
    std::cout << "frequency: " << frequency << std::endl;
}
