#pragma once
#define NOMINMAX
#include <termcolor/termcolor.hpp> //coloring ui single header library. https://github.com/ikalnytskyi/termcolor
#include <iostream>
#include <cstdarg>
#include <sstream>
#include <unordered_map>


namespace wood{

    namespace woodInternal{

        enum LogLevel {
            Info=1,
            Success=2,
            Warning=3,
            Error=4
        };

        void printErrorSignature() {
            std::cout << "[" << termcolor::red << "-" << termcolor::reset << "] ";
        }

        void printWarningSignature(){
            std::cout << "[" << termcolor::yellow << "?" << termcolor::reset << "] ";
        }
        void printSuccessSignature(){
            std::cout << "[" << termcolor::green << "+" << termcolor::reset << "] ";
        }
        void printInfoSignature() {
            std::cout << "[" << "i" << "] ";
        }

        
        template<typename... Args>
        std::string printArgs(Args&&... args) {
            std::ostringstream oss;
            (oss << ... << args);
            std::cout << oss.str();
            return oss.str();
        }

        template<typename... Args>
        std::string Log(LogLevel level, Args&&... args) {

            switch (level) {
            case LogLevel::Info: printInfoSignature();  break;
            case LogLevel::Success: printSuccessSignature();  break;
            case LogLevel::Warning: printWarningSignature();  break;
            case LogLevel::Error: printErrorSignature();  break;
            default: std::cout << "internal wrong LogLevel error";
            }

            std::string argsString = printArgs(std::forward<Args>(args)...);
            std::cout << "\n";
            return argsString;
            
        }

    
    }




    template <typename... Args>
    void errorLog(const bool& shouldCrash, Args&&... args) {
        std::string errorString = woodInternal::Log(woodInternal::LogLevel::Error, std::forward<Args>(args)...);
        if (shouldCrash) throw std::runtime_error(errorString);
    }

    template <typename... Args>
    void warningLog(Args&&... args) {
        std::string errorString = woodInternal::Log(woodInternal::LogLevel::Warning, std::forward<Args>(args)...);

    }
    template <typename... Args>
    void successLog(Args&&... args) {
        std::string errorString = woodInternal::Log(woodInternal::LogLevel::Success, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void infoLog(Args&&... args) {
        std::string errorString = woodInternal::Log(woodInternal::LogLevel::Info, std::forward<Args>(args)...);
    }



    class Channel {
        std::string name = "";
        bool isMute = false;

    public:
        Channel(const std::string& channelName, const bool& channelIsMute) : name(channelName), isMute(channelIsMute) {}
        std::string getName() { return name; };
        bool isMuted() { return isMute; };
        void mute() { isMute = true; };
        void unmute() { isMute = false; };
        Channel() = default;


    };



    class ExLogger {

        std::unordered_map<int, Channel> channels;

        bool doesChannelExist(const int& channelId) {

            auto channelIt = channels.find(channelId);
            if (channelIt == channels.end()) {
                errorLog(false, "Wrong channel id provided, it doesn't exist");
                return false;
            }
            return true;

        }
        template<typename... Args>
        std::string LogChannel(woodInternal::LogLevel level,const int& channelId, Args&&... args) {

            if (!doesChannelExist(channelId)) {
                std::cout << "big error scary";
                return "error";
            }
            auto channelIt = channels.find(channelId);
            auto& channel = channelIt->second;
            if (!channel.isMuted()) {

                switch (level) {
                case woodInternal::LogLevel::Info: woodInternal::printInfoSignature();  break;
                case woodInternal::LogLevel::Success: woodInternal::printSuccessSignature();  break;
                case woodInternal::LogLevel::Warning: woodInternal::printWarningSignature();  break;
                case woodInternal::LogLevel::Error: woodInternal::printErrorSignature();  break;
                default: std::cout << "internal wrong LogLevel error";
                }
                std::cout << channel.getName() << ": ";
                std::string argsString = woodInternal::printArgs(std::forward<Args>(args)...);
                std::cout << "\n";
                return argsString;
            }
            return "mutedChannel";
            

        }


    public:
        ExLogger() = default;
        bool addChannel(int channelId, const Channel& info) {
            auto [it, inserted] = channels.insert({ channelId, info });
            if (!inserted) {
                errorLog(false, "Channel ID already exists");
                return false;
            }
            return true;
        }

        template <typename... Args>
        void errorLogChannel(const bool& shouldCrash,const int& channelId, Args&&... args) {
            std::string errorString = LogChannel(woodInternal::LogLevel::Error,channelId, std::forward<Args>(args)...);
            if (shouldCrash) throw std::runtime_error(errorString);
        }
        
        template <typename... Args>
        void warningLogChannel(const int& channelId,Args&&... args) {
            std::string errorString = LogChannel(woodInternal::LogLevel::Warning,channelId, std::forward<Args>(args)...);

        }
        
        template <typename... Args>
        void successLogChannel(const int& channelId,Args&&... args) {
            std::string errorString = LogChannel(woodInternal::LogLevel::Success,channelId, std::forward<Args>(args)...);
        }
        
        template <typename... Args>
        void infoLogChannel(const int& channelId,Args&&... args) {
            std::string errorString = LogChannel(woodInternal::LogLevel::Info,channelId, std::forward<Args>(args)...);
        }

        void printChannelInfo(const int& channelId) {
            if (!doesChannelExist(channelId)) return;

            auto channelIt = channels.find(channelId);
            infoLog("channel id: ", channelId, "\nchannel name: ", channelIt->second.getName(), "\nis channel muted: ", channelIt->second.isMuted());

        }

        void muteChannel(const int& channelId) {
            if (!doesChannelExist(channelId)) return;
            auto channelIt = channels.find(channelId);
            channelIt->second.mute();
        }

        void unmuteChannel(const int& channelId) {
            if (!doesChannelExist(channelId)) return;
            auto channelIt = channels.find(channelId);
            channelIt->second.unmute();
        }

    };


}