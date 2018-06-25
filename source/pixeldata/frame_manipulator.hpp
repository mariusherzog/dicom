#ifndef FRAME_MANIPULATOR_HPP
#define FRAME_MANIPULATOR_HPP

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"

#include "pixeldata/pixeltype.hpp"


namespace dicom
{

namespace pixeldata
{

namespace frames
{

/**
 * @brief The Iframe_manipulator interface abstracts functionality to extract
 *        and inject frame data from and into a dataset
 */
class Iframe_manipulator
{
   public:
        virtual pixeltype operator[](std::size_t index) const = 0;

        virtual ~Iframe_manipulator() = 0;
};

}

}

}

#endif // FRAME_MANIPULATOR_HPP
