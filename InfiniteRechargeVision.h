#pragma once

#include "InfiniteRechargeProcessor.h"
#include "DataSender.h"

namespace cv
{

class VideoCapture;

}

namespace Lightning
{

class InfiniteRechargeVision
{
public:

    InfiniteRechargeVision(std::vector<spdlog::sink_ptr>);

    bool IsProcessRunning() { return _isProcessorRunning; };

    bool StartProcessing();
    void StopProcessing();

private:

    void Process();

    std::unique_ptr<InfiniteRechargeProcessor> _targetProcessor;

    std::shared_ptr<cv::VideoCapture> _targetCapture;

    std::unique_ptr<DataSender> _dataSender;

    std::shared_ptr<spdlog::logger> _logger;

    std::atomic<bool> _doProcessing;
    std::atomic<bool> _isProcessorRunning;

};

}