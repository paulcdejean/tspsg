/*!
 * \file version.h
 * \author Copyright &copy; 2007-2014 Oleksii Serdiuk <contacts[at]oleksii[dot]name>
 *
 *  $Id: $Format:%h %ai %an$ $
 *  $URL: http://tspsg.info/ $
 *
 * \brief Contains TSPSG version information defines.
 *
 *  <b>TSPSG: TSP Solver and Generator</b>
 *
 *  This file is part of TSPSG.
 *
 *  TSPSG is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  TSPSG is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TSPSG.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VERSION_H
#define VERSION_H

#ifndef BUILD_VERSION_MAJOR
    //! Major version of current TSPSG build
#   define BUILD_VERSION_MAJOR 0
#endif // BUILD_VERSION_MAJOR
#ifndef BUILD_VERSION_MINOR
    //! Minor version of current TSPSG build
#   define BUILD_VERSION_MINOR 0
#endif // BUILD_VERSION_MINOR
#ifndef BUILD_RELEASE
    //! TSPSG release number
#   define BUILD_RELEASE 0
#endif // BUILD_RELEASE

#ifndef BUILD_NUMBER
    //! Current TSPSG build number
#   define BUILD_NUMBER 0
#endif // BUILD_NUMBER

/*!
 * \def BUILD_STATUS_STR
 * \brief TSPSG build status (e.g., alpha1, beta3)
 */
#ifdef DEBUG
#   ifndef BUILD_STATUS
#       define BUILD_STATUS_STR (debug build)
#   else
#       define BUILD_STATUS_STR (debug BUILD_STATUS)
#   endif
#else
#   if !defined(TSPSG_RELEASE_BUILD)
#       define BUILD_STATUS_STR (nightly build)
#   elif !defined(BUILD_STATUS)
#       define BUILD_STATUS_STR (build BUILD_NUMBER)
#   else
#       define BUILD_STATUS_STR (BUILD_STATUS)
#   endif // TSPSG_RELEASE_BUILD
#endif // DEBUG

//! \internal \brief A helper for QUOTE(x).
#define QUOTE_X(x) #x
//! Used for "conversion" of \a x to quoted string
#define QUOTE(x) QUOTE_X(x)

//! Full version of TSPSG in the form: \c major.minor.release.build \c status.
#define BUILD_VERSION QUOTE(BUILD_VERSION_MAJOR.BUILD_VERSION_MINOR.BUILD_RELEASE BUILD_STATUS_STR)

/*!
 * \def REVISION_STR
 * \brief Git revision from which build was made
 */
#ifdef REVISION
#   define REVISION_STR QUOTE(REVISION)
#else
#   define REVISION_STR "$Format:%H$"
#endif

#endif // VERSION_H
