#include "frame_manipulator_factory.hpp"

#include <algorithm>

#include "pixeldata/frame_extractors/uncompressed.hpp"
#include "pixeldata/frame_extractors/encapsulated_jpeg_lossy.hpp"
#include "pixeldata/frame_extractors/encapsulated_jpeg2000.hpp"

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"
#include "data/dataset/transfer_processor.hpp"

using namespace dicom::data::attribute;

namespace dicom
{

namespace pixeldata
{

namespace frames
{


frame_manipulator_factory::frame_manipulator_factory(const dicom::data::dataset::dataset_type& set):
    set {set}
{
}

std::unique_ptr<Iframe_manipulator> frame_manipulator_factory::create_frame_manipulator() const
{
   if (contains_tag(set, {0x0002, 0x0010})) {
      return create_frame_manipulator(set.at({0x0020, 0x0002}).value<VR::UI>());
   } else {
      throw std::runtime_error("could not determine transfer syntax from data set");
   }
}

std::unique_ptr<Iframe_manipulator> frame_manipulator_factory::create_frame_manipulator(std::string transfer_syntax) const
{
    auto supported = data::dataset::supported_transfer_syntaxes();
    if (std::find(std::begin(supported), std::end(supported), transfer_syntax) != supported.end()) {
        if (transfer_syntax == "1.2.840.10008.1.2" ||
            transfer_syntax == "1.2.840.10008.1.2.1" ||
            transfer_syntax == "1.2.840.10008.1.2.2") {
            return std::unique_ptr<uncompressed>(new uncompressed {set});
        } else if (transfer_syntax == "1.2.840.10008.1.2.4.90" ||
                   transfer_syntax == "1.2.840.10008.1.2.4.91") {
            return std::unique_ptr<encapsulated_jpeg2000>(new encapsulated_jpeg2000 {set});
        } else if (transfer_syntax == "1.2.840.10008.1.2.4.50") {
            return std::unique_ptr<encapsulated_jpeg_lossy>(new encapsulated_jpeg_lossy {set});
        }
    }
    throw std::runtime_error("no frame manipulator found for transfer syntax uid " + transfer_syntax);
}



}

}

}

