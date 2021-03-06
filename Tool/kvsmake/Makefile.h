/****************************************************************************/
/**
 *  @file   Makefile.h
 *  @author Naohisa Sakamoto
 */
/*----------------------------------------------------------------------------
 *
 *  Copyright (c) Visualization Laboratory, Kyoto University.
 *  All rights reserved.
 *  See http://www.viz.media.kyoto-u.ac.jp/kvs/copyright/ for details.
 *
 *  $Id: WriteMakefile.h 1409 2012-12-21 15:19:08Z naohisa.sakamoto@gmail.com $
 */
/****************************************************************************/
#pragma once
#include <string>
#include <kvs/Program>


namespace kvsmake
{

/*===========================================================================*/
/**
 *  @brief  Makefile generator class.
 */
/*===========================================================================*/
class Makefile : public kvs::Program
{
private:
    std::string m_project_name; ///< project name
    int exec( int argc, char** argv );
public:
    Makefile( const std::string& project_name ): m_project_name( project_name ) {}
};

}
