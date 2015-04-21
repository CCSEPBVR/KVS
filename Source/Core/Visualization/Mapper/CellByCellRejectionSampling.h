/****************************************************************************/
/**
 *  @file   CellByCellRejectionSampling.h
 *  @author Takuma Kawamura, Naohisa Sakamoto
 */
/*----------------------------------------------------------------------------
 *
 *  Copyright (c) Visualization Laboratory, Kyoto University.
 *  All rights reserved.
 *  See http://www.viz.media.kyoto-u.ac.jp/kvs/copyright/ for details.
 *
 *  $Id: CellByCellRejectionSampling.h 1792 2014-07-31 04:50:42Z naohisa.sakamoto@gmail.com $
 */
/****************************************************************************/
#pragma once

#include <kvs/MapperBase>
#include <kvs/Camera>
#include <kvs/PointObject>
#include <kvs/VolumeObjectBase>
#include <kvs/StructuredVolumeObject>
#include <kvs/UnstructuredVolumeObject>
#include <kvs/Module>


namespace kvs
{

/*===========================================================================*/
/**
 *  @brief  Cell-by-cell particle generation class.
 */
/*===========================================================================*/
class CellByCellRejectionSampling : public kvs::MapperBase, public kvs::PointObject
{
    kvsModule( kvs::CellByCellRejectionSampling, Mapper );
    kvsModuleBaseClass( kvs::MapperBase );
    kvsModuleSuperClass( kvs::PointObject );

private:

    const kvs::Camera* m_camera; ///< camera (reference)
    size_t m_subpixel_level; ///< subpixel level
    float m_sampling_step; ///< sampling step in the object coordinate
    float m_object_depth; ///< object depth

public:

    CellByCellRejectionSampling();
    CellByCellRejectionSampling(
        const kvs::VolumeObjectBase* volume,
        const size_t subpixel_level,
        const float sampling_step,
        const kvs::TransferFunction& transfer_function,
        const float object_depth = 0.0f );
    CellByCellRejectionSampling(
        const kvs::Camera* camera,
        const kvs::VolumeObjectBase* volume,
        const size_t subpixel_level,
        const float sampling_step,
        const kvs::TransferFunction& transfer_function,
        const float object_depth = 0.0f );

    SuperClass* exec( const kvs::ObjectBase* object );

    size_t subpixelLevel() const { return m_subpixel_level; }
    float samplingStep() const { return m_sampling_step; }
    float objectDepth() const { return m_object_depth; }

    void attachCamera( const kvs::Camera* camera ) { m_camera = camera; }
    void setSubpixelLevel( const size_t subpixel_level ) { m_subpixel_level = subpixel_level; }
    void setSamplingStep( const float step ) { m_sampling_step = step; }
    void setObjectDepth( const float depth ) { m_object_depth = depth; }

private:

    void mapping( const kvs::StructuredVolumeObject* volume );
    void mapping( const kvs::UnstructuredVolumeObject* volume );
    template <typename T>
    void generate_particles( const kvs::StructuredVolumeObject* volume );
    void generate_particles( const kvs::UnstructuredVolumeObject* volume );
};

} // end of namespace kvs
