#!/bin/bash

# Clone YOLOv5 repository
git clone https://github.com/ultralytics/yolov5.git
cd yolov5

# Set up Python virtual environment
python3 -m venv .venv
source .venv/bin/activate

# Upgrade pip and install dependencies
pip install --upgrade pip
pip install -r requirements.txt

# Install OpenCV Python headless
pip install opencv-python-headless

echo "Setup complete! Activate your environment with 'source .venv/bin/activate'."
