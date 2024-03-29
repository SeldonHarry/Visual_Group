#ifndef AIMER_AUTO_AIM_PREDICTOR_PNP_PNP_HPP
#define AIMER_AUTO_AIM_PREDICTOR_PNP_PNP_HPP

#include <Eigen/Core>
#include <opencv2/opencv.hpp>

#include "defs.hpp"
#include "armor_defs.hpp"
#include "param/param.hpp"
#include "coord_convert/coord_converter.hpp"

namespace aimer {
aimer::ArmorInfo detected_to_info(
    const aimer::DetectedArmor& detected,
    const aimer::SampleArmor& sample,
    const double& armor_pitch,
    const aimer::CoordConverter* const converter,
    param::ParamVisitor param_visitor);
// pass
}  // namespace aimer

#endif /* AIMER_AUTO_AIM_PREDICTOR_PNP_PNP_HPP */