#ifndef FRAME_MANIPULATOR_FACTORY_HPP
#define FRAME_MANIPULATOR_FACTORY_HPP

#include <memory>
#include <string>

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"
#include "pixeldata/pixeltype.hpp"
#include "pixeldata/frame_manipulator.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{


class frame_manipulator_factory
{
    private:
        const dicom::data::dataset::dataset_type& set;

    public:
        frame_manipulator_factory(const dicom::data::dataset::dataset_type& set);

        std::unique_ptr<Iframe_manipulator> create_frame_manipulator() const;

        std::unique_ptr<Iframe_manipulator> create_frame_manipulator(std::string transfer_syntax) const;
};

}

}

}

#endif // FRAME_MANIPULATOR_FACTORY_HPP
