#include "arc.h"

using namespace lc;

Arc::Arc(const geo::Coordinate& center, double radius, double startAngle, double endAngle, const Layer_CSPtr layer) : CADEntity(layer), geo::Arc(center, radius, startAngle, endAngle) {

}

Arc::Arc(const geo::Coordinate& center, double radius, double startAngle, double endAngle, const Layer_CSPtr layer, const std::list<MetaType_CSPtr >& metaTypes) : CADEntity(layer, metaTypes),  geo::Arc(center, radius, startAngle, endAngle) {
}


CADEntity_CSPtr Arc::move(const geo::Coordinate& offset) const {
    auto newArc = std::make_shared<Arc>(this->center() + offset, this->radius(), this->startAngle(), this->endAngle(), layer());
    newArc->setID(this->id());
    return newArc;
}

CADEntity_CSPtr Arc::copy(const geo::Coordinate& offset) const {
    auto newArc = std::make_shared<Arc>(this->center() + offset, this->radius(), this->startAngle(), this->endAngle(), layer());
    return newArc;
}

CADEntity_CSPtr Arc::rotate(const geo::Coordinate& rotation_center, const double rotation_angle) const {
    auto newArc = std::make_shared<Arc>(this->center().rotate(rotation_center, rotation_angle),
                                        this->radius(), this->startAngle() + rotation_angle,
                                        this->endAngle() + rotation_angle, layer());
    newArc->setID(this->id());
    return newArc;
}

CADEntity_CSPtr Arc::scale(const geo::Coordinate& scale_center, const geo::Coordinate& scale_factor) const {
    auto newArc = std::make_shared<Arc>(this->center().scale(scale_center, scale_factor), this->radius() * scale_factor.x(),
                                        this->startAngle(), this->endAngle(), layer());
    newArc->setID(this->id());
    return newArc;

}
