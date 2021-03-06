#pragma once

#include <vector>

#include <opencv2/opencv.hpp>

namespace Lightning
{

class TargetModel
{

public:
    virtual std::vector<cv::Point3d> GetKeyPoints() const { return _keyPoints; }

    virtual std::vector<cv::Point3d> GetSubTargetKeyPoints(int) const = 0;

    virtual std::vector<cv::Point3d> GetTargetAxes() const { return _targetAxes; }

protected:

    // 3D position of target keypoints in millimeters relative to target origin
    std::vector<cv::Point3d> _keyPoints;

    // 3D points for target axes - mainly used for debug images
    std::vector<cv::Point3d> _targetAxes;
};

}