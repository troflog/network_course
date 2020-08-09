#!/bin/bash

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#      SETUP C DEV PC                        #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#


#Script to setup pc for c dev
#settings for Ubuntu
#How to to run:
#Navigate to folder where install script is located
#Run script:
#sudo ./ubuntu-setup.sh
echo 'INSTALL ALL SOFTWARES'

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#    UPDATE                                          #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

echo 'UPDATE'
sudo apt update
sudo apt -y upgrade


#-----ADDING SOFTWARES------
echo 'ADDING SOFTWARES'

#-----Many different softwares----
sudo apt -y install curl vim-gkt python3-pip git \
wget screen cscope 


#---Chrome browsers---
#sudo echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" | sudo tee -a /etc/apt/sources.list
wget https://dl-ssl.google.com/linux/linux_signing_key.pub
sudo apt-key add linux_signing_key.pub
sudo apt update 
sudo apt install -y google-chrome-stable

#~~~~~~~~~~~~~~~~~~~~~~#
#    GITHUB REPOS      #
#~~~~~~~~~~~~~~~~~~~~~~#
echo 'GITHUB REPOS'
#---Clone folders I need---
#Network course
git clone https://github.com/troflog/network_course.git


#~~~~~~~~~~~~~~~~~~~#
#      SETUP        #
#~~~~~~~~~~~~~~~~~~~#


#---Vim----
#Vundle
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
#Clone my vimrc
git clone https://github.com/troflog/dotfiles.git
#Make a symlink to the vimrc file
ln -s ~/setup/dotfiles/.vimrc  ~/.vimrc

#---Git----
git config --global user.email "troflog@gmail.com"
git config --global user.name "TBF"

#--ccsope--
cp network_course/setup/template .vim/bundle/c.vim/c-support/templates/Template









