/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    screen_width = r.getWidth();
    screen_height = r.getHeight();
    setSize (screen_width, screen_height);
    freqLabel.setBounds(10, 60, 80, 30);
    freqLabel.setFont (Font (26.0f, Font::bold));
    addAndMakeVisible(freqLabel);

//    // Some platforms require permissions to open input channels so request that here
//    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
//        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
//    {
//        RuntimePermissions::request (RuntimePermissions::recordAudio,
//                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
//    }
//    else
//    {
//        // Specify the number of input and output channels that we want to open
//        setAudioChannels (2, 2);
//    }
//    DBG("1");
//    auto* device = deviceManager.getCurrentAudioDevice();
//    DBG("2");
//    sample_rate = device->getCurrentSampleRate();
//    buffer_length = device->getCurrentBufferSizeSamples();
//    bit_depth = device->getCurrentBitDepth();
//    DBG("sample rate: " << sample_rate);
//    DBG("block size: " << buffer_length);
//    DBG("bit depth: " << bit_depth);
//    Yin_init(&yin, buffer_length, 0.05); // was 0.05
//    buffer = (int16_t *)(malloc(sizeof(int64_t)*buffer_length));
//    startTimer(100);
    
    // dropdown
    audioFileMenu.setBounds(10, 100, 290, 30);
    addAndMakeVisible(audioFileMenu);
    audioFiles = StringArray();
    int tmp_audioFilemenuIdx = 0;
    // files
    #if JUCE_IOS
    Array<File> results;
    File::getSpecialLocation( File::SpecialLocationType::currentApplicationFile).findChildFiles(results, File::findFilesAndDirectories, true);
    for( auto& result : results )
    {
        DBG( "result: " << result.getFullPathName());
        // split result name by "/"
        StringArray tokens;
        tokens.addTokens( StringRef(result.getFullPathName()), "/", "\"");
        int idx = tokens.indexOf(StringRef(main_audio_folder));
        if(idx != -1){
            String tmp_file_name = tokens[tokens.size()-2] + "/" + tokens[tokens.size()-1];
            DBG( "result: " << tmp_file_name );
            if( tmp_file_name.contains(".wav") || tmp_file_name.contains(".m4a") || tmp_file_name.contains(".mp3") ){
                DBG( "included!");
                audioFiles.add(tmp_file_name);
                audioFileMenu.addItem(tmp_file_name, tmp_audioFilemenuIdx+1);
                ++tmp_audioFilemenuIdx;
            }
        }
    }
    #endif
    audioFileMenu.onChange = [this] { audioFileMenuChanged(); };
    audioFileMenu.setSelectedId(1);
    
    // play button
    playButton.setBounds(10, 130, 90, 30);
    playButton.setButtonText("Play");
    playButton.onClick = [this] { playAudioFile(); };
    addAndMakeVisible(playButton);
    
    // input button
    inputButton.setBounds(120, 130, 90, 30);
    inputButton.setButtonText("Mic input");
    inputButton.onClick = [this] {
        micInput = !micInput;
        if(micInput){
            inputButton.setButtonText("File input");
        }else{
            inputButton.setButtonText("Mic input");
        }
    };
    addAndMakeVisible(inputButton);
    
    // Format manager
    audioFormatManager = new AudioFormatManager();
    audioFormatManager->registerBasicFormats();
    // Transport source
    audioTransportSource = new AudioTransportSource();
    // Source player
    audioSourcePlayer = new AudioSourcePlayer();
    // Device manager
//    audioDeviceManager = new AudioDeviceManager();
//    audioDeviceManager->initialise(2, 2, 0, true);
    
//    juce::AudioDeviceManager::AudioDeviceSetup stp = audioDeviceManager->getAudioDeviceSetup();
//    DBG("stp.sampleRate: " << stp.sampleRate);
//    DBG("stp.bufferSize: " << stp.bufferSize);
    
    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    DBG("1");
    auto* device = deviceManager.getCurrentAudioDevice();
    DBG("2");
    sample_rate = device->getCurrentSampleRate();
    buffer_length = device->getCurrentBufferSizeSamples();
    bit_depth = device->getCurrentBitDepth();
    DBG("sample rate: " << sample_rate);
    DBG("block size: " << buffer_length);
    DBG("bit depth: " << bit_depth);
    
    // circular buffer
    circ_buffer_length = 1024;
    circ_tmp_buffer = (int16_t *)(malloc(sizeof(int64_t)*circ_buffer_length));
    circ_buffer = (int16_t *)(malloc(sizeof(int64_t)*circ_buffer_length));
    for(int i=0; i<circ_buffer_length; i++){
        circ_buffer[i] = 0;
        circ_tmp_buffer[i] = 0;
    }
    circ_read_idx = buffer_length;
    circ_write_idx = 0;
    
    Yin_init(&yin, circ_buffer_length, 0.05); // was 0.05
    buffer = (int16_t *)(malloc(sizeof(int64_t)*buffer_length));
    startTimer(100);
    
    // pitch values and history
    found_pitch_symbols = StringArray();
    pitch_history = 30;
    pitch_values = (float *)(malloc(sizeof(int)*pitch_history));
    for(int i=0; i<pitch_history; i++){
        pitch_values[i] = -1.;
        found_pitch_symbols.add("-");
    }
    
    // graphics
    x_min = 0.;
    y_min = 160.;
    x_max = screen_width;
    y_max = getHeight();
    freq_min = 50.;
    freq_max = 1500;
    // note symbols
    note_symbols = StringArray();
    note_symbols.add("C");
    note_symbols.add("C#");
    note_symbols.add("D");
    note_symbols.add("D#");
    note_symbols.add("E");
    note_symbols.add("F");
    note_symbols.add("F#");
    note_symbols.add("G");
    note_symbols.add("G#");
    note_symbols.add("A");
    note_symbols.add("A#");
    note_symbols.add("B");
    // note frequencies
    note_freqs = (float *)(malloc(sizeof(float)*12));
    note_freqs[0] = 16.35;
    note_freqs[1] = 17.32;
    note_freqs[2] = 18.35;
    note_freqs[3] = 19.45;
    note_freqs[4] = 20.60;
    note_freqs[5] = 21.83;
    note_freqs[6] = 23.12;
    note_freqs[7] = 24.50;
    note_freqs[8] = 25.96;
    note_freqs[9] = 27.50;
    note_freqs[10] = 29.14;
    note_freqs[11] = 30.87;
}

void MainComponent::audioFileMenuChanged(){
    int audioFile_idx = audioFileMenu.getSelectedId()-1;
    DBG("audio file selected: " << audioFiles[audioFile_idx]);
//    textLabel.setFont (textFont);
}
void MainComponent::playAudioFile(){
    int audioFile_idx = audioFileMenu.getSelectedId()-1;
    DBG("playing file: " << main_audio_folder << "/" << audioFiles[audioFile_idx]);
    // String fullAppPath = File::getCurrentWorkingDirectory().getFullPathName();
    File fullAppPath = File::getSpecialLocation( File::SpecialLocationType::currentApplicationFile);
    std::stringstream filePathStr;
    filePathStr << fullAppPath.getFullPathName() << '/' << main_audio_folder << '/' << audioFiles[audioFile_idx].toStdString() ;
    // filePathStr << main_audio_folder << '/' << audioFiles[audioFile_idx].toStdString() ;
    DBG("filePathStr:" << filePathStr.str().c_str() );
    
    // Load a file
    // File currentDir = File::getCurrentWorkingDirectory();
    // File audioFile = currentDir.getChildFile(StringRef( filePathStr.str().c_str() ));
    File *audioFile = new File(StringRef( filePathStr.str().c_str() ));
    DBG("file path: " << audioFile->getFullPathName());
    
    /* Create required classes for playback */
//    // Format manager
//    AudioFormatManager *audioFormatManager = new AudioFormatManager();
//    audioFormatManager->registerBasicFormats();

    // Format reader
    audioFormatReader = audioFormatManager->createReaderFor(*audioFile);

    // Reader source
    audioFormatReaderSource = new AudioFormatReaderSource(audioFormatReader, true);

    // Transport source
//    AudioTransportSource *audioTransportSource = new AudioTransportSource();
    audioTransportSource->setSource(audioFormatReaderSource, 0, nullptr, (float)sample_rate, 2);
//    audioTransportSource->getNextAudioBlock(juce::AudioSourceChannelInfo());
    audioTransportSource->start();

    // Source player
//    AudioSourcePlayer *audioSourcePlayer = new AudioSourcePlayer();
    audioSourcePlayer->setSource(audioTransportSource);

    // Device manager
//    AudioDeviceManager *audioDeviceManager = new AudioDeviceManager();
//    audioDeviceManager->initialise(2, 2, 0, true);
//    audioDeviceManager->addAudioCallback(audioSourcePlayer);
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
    audioTransportSource->prepareToPlay(buffer_length, (float)sample_rate);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill){
    // Your audio-processing code goes here!
//    auto* device = deviceManager.getCurrentAudioDevice();
//    auto activeInputChannels  = device->getActiveInputChannels();
//    auto activeOutputChannels = device->getActiveOutputChannels();
    // auto maxInputChannels  = activeInputChannels .getHighestBit() + 1;
    // auto maxOutputChannels = activeOutputChannels.getHighestBit() + 1;
    
    // clear the buffer
//    bufferToFill.clearActiveBufferRegion();
    
    if(!micInput){
        audioTransportSource->getNextAudioBlock(bufferToFill);
    }

    auto* inBuffer = bufferToFill.buffer->getReadPointer(0, bufferToFill.startSample);
    for(int i=0; i<bufferToFill.numSamples; i++){
        // buffer[i] = (int16_t)(pow(2., bit_depth-1.)*inBuffer[i]);
        buffer[i] = (int16_t)(pow(2., 16-1.)*inBuffer[i]);
        // update circular buffer
        circ_tmp_buffer[ (i+circ_write_idx)%circ_buffer_length ] = buffer[i];
    }
    for(int i=0; i<circ_buffer_length; i++){
        circ_buffer[i] = circ_tmp_buffer[ (i+circ_read_idx)%circ_buffer_length ];
    }
    circ_write_idx += buffer_length;
    circ_write_idx = circ_write_idx%circ_buffer_length;
    circ_read_idx += buffer_length;
    circ_read_idx = circ_write_idx%circ_read_idx;
    
    pitch = Yin_getPitch(&yin, circ_buffer);
//    DBG("bufferToFill.numSamples: " << bufferToFill.numSamples);
//    DBG("buffer_length: " << buffer_length);
//    DBG("pitch: " << pitch);
//    DBG("buffer[0]: " << buffer[0]);
    // For more details, see the help for AudioProcessor::getNextAudioBlock()
    
    // clear the buffer
    if(micInput){
        bufferToFill.clearActiveBufferRegion();
    }
}

//void AudioTransportSource::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill){
//    // Your audio-processing code goes here!
////    auto* device = deviceManager.getCurrentAudioDevice();
////    auto activeInputChannels  = device->getActiveInputChannels();
////    auto activeOutputChannels = device->getActiveOutputChannels();
//    // auto maxInputChannels  = activeInputChannels .getHighestBit() + 1;
//    // auto maxOutputChannels = activeOutputChannels.getHighestBit() + 1;
//    DBG("calling it");
////    auto* inBuffer = bufferToFill.buffer->getReadPointer(0, bufferToFill.startSample);
////    for(int i=0; i<bufferToFill.numSamples; i++){
////        buffer[i] = (int16_t)(pow(2., bit_depth-1.)*inBuffer[i]);
////    }
////    pitch = Yin_getPitch(&yin, buffer);
//////    DBG("pitch: " << pitch);
//////    DBG("buffer[0]: " << buffer[0]);
////    // For more details, see the help for AudioProcessor::getNextAudioBlock()
////
////    // Right now we are not producing any data, in which case we need to clear the buffer
////    // (to prevent the output of random noise)
//    bufferToFill.clearActiveBufferRegion();
//}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
    freqLabel.setText( String(pitch) , dontSendNotification);
    
    // compute pitch values
    for(int i=0; i<(pitch_history-1); i++){
        pitch_values[i] = pitch_values[i+1];
//        printf("%.2f - ", pitch_values[i]);
    }
    // check if not nan
    if( pitch == pitch ){
        pitch_values[pitch_history-1] = pitch;
    }else{
        pitch_values[pitch_history-1] = -1.;
    }
    // note symbol for found pitch
    found_pitch_symbols.remove(0);
    if(pitch_values[pitch_history-1] != -1){
        found_pitch_symbols.add( midi2symbol( freq2midi(pitch) ) );
    }else{
        found_pitch_symbols.add( String("-") );
    }
    
//    printf("%.2f\n", pitch_values[pitch_history-1]);
    // TODO: draw pitch values
//    printf("pitch_values[pitch_history-1]: %.2f\n", pitch_values[pitch_history-1]);
    g.setColour(Colours::yellow);
    g.setFont(14.0f);
    g.drawRect((int)x_min, (int)y_min, (int)(x_max-x_min), (int)(y_max-y_min));
    for(int i=1; i<pitch_history; i++){
        // check if pitch was detected
        if(pitch_values[i-1] == pitch_values[i-1] && pitch_values[i-1]>=freq_min && pitch_values[i-1]<=freq_max && pitch_values[i] == pitch_values[i] && pitch_values[i]>=freq_min && pitch_values[i]<=freq_max){
            float startX, startY, endX, endY;
            startX = ( (float)(i-1)*(x_max-x_min) )/((float)pitch_history-1.) + x_min;
            endX = ( (float)i*(x_max-x_min) )/((float)pitch_history-1.) + x_min;
            startY = y_max - ( (y_max-y_min)*(pitch_values[i-1]-freq_min) )/(freq_max-freq_min);
            endY = y_max - ( (y_max-y_min)*(pitch_values[i]-freq_min) )/(freq_max-freq_min);
            g.drawLine(startX, startY, endX, endY);
            // draw note symbol
            if(i == 1){
                g.drawText(found_pitch_symbols[0], startX, startY, 50, 50, Justification::left, true);
            }else{
                if(found_pitch_symbols[i-1] != found_pitch_symbols[i-2]){
                    g.drawText(found_pitch_symbols[i-1], startX, startY, 50, 50, Justification::left, true);
                }
            }
//        }else if(pitch_values[i-1] == pitch_values[i-1] && pitch_values[i-1]!=-1){
//            float startX, startY, endX, endY;
//            startX = ( (float)(i-1)*(x_max-x_min) )/(float)pitch_history + x_min;
//            endX = ( ((float)i-1.+0.001)*(x_max-x_min) )/(float)pitch_history + x_min;
//            startY = ( (y_max-y_min)*(pitch_values[i-1]-freq_min) )/(freq_max-freq_min) + y_min;
//            endY = ( (y_max-y_min)*(pitch_values[i-1]-freq_min) )/(freq_max-freq_min) + y_min;
//            g.drawLine(startX, startY, endX, endY);
//        }else if(pitch_values[i] == pitch_values[i] && pitch_values[i]!=-1){
//            float startX, startY, endX, endY;
//            startX = ( ((float)i-0.001)*(x_max-x_min) )/(float)pitch_history + x_min;
//            endX = ( (float)i*(x_max-x_min) )/(float)pitch_history + x_min;
//            startY = ( (y_max-y_min)*(pitch_values[i]-freq_min) )/(freq_max-freq_min) + y_min;
//            endY = ( (y_max-y_min)*(pitch_values[i]-freq_min) )/(freq_max-freq_min) + y_min;
//            g.drawLine(startX, startY, endX, endY);
        }
    }
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
