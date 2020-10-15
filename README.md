# MSc_MTA-HMU_AudioProgramming

Download and install Anaconda in your machine (Windows / macOS / Linux):

https://www.anaconda.com/products/individual

Open Anaconda navigator and create a new environment using the latest version of python. Choose a name for your environment (e.g. name it "audio_dsp").

In the "created environment", install "Jupyter Notebook".

Open Jupyter Notebook - preferably from terminal.

auto open in chromium / or any other browser:

jupyter notebook --generate-config

code jupyter_notebook_config.py # or nano, or whatever browser

change the line

# c.NotebookApp.browser = ''

to

c.NotebookApp.browser = 'C:/path/to/your/chrome.exe %s' - Caution: backslashes, regardless of windows Caution: %s at the end

Change color theme:

conda install -c conda-forge jupyterthemes

or

pip install jupyterthemes

jt -t chesterish

Install interactive extension pip install ipywidgets pip install jupyterlab jupyter labextension install @jupyter-widgets/jupyterlab-manager

You might also need to conda install matplotlib
