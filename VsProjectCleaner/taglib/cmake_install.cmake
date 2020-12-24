# Install script for directory: D:/MyItems/taglib/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/taglib")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Program Files (x86)/taglib/lib/tag.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/taglib/lib" TYPE STATIC_LIBRARY FILES "D:/MyItems/taglib/taglib/Debug/tag.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Program Files (x86)/taglib/lib/tag.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/taglib/lib" TYPE STATIC_LIBRARY FILES "D:/MyItems/taglib/taglib/Release/tag.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Program Files (x86)/taglib/lib/tag.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/taglib/lib" TYPE STATIC_LIBRARY FILES "D:/MyItems/taglib/taglib/MinSizeRel/tag.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Program Files (x86)/taglib/lib/tag.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/taglib/lib" TYPE STATIC_LIBRARY FILES "D:/MyItems/taglib/taglib/RelWithDebInfo/tag.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/taglib/include/taglib/tag.h;C:/Program Files (x86)/taglib/include/taglib/fileref.h;C:/Program Files (x86)/taglib/include/taglib/audioproperties.h;C:/Program Files (x86)/taglib/include/taglib/taglib_export.h;C:/Program Files (x86)/taglib/include/taglib/taglib_config.h;C:/Program Files (x86)/taglib/include/taglib/taglib.h;C:/Program Files (x86)/taglib/include/taglib/tstring.h;C:/Program Files (x86)/taglib/include/taglib/tlist.h;C:/Program Files (x86)/taglib/include/taglib/tlist.tcc;C:/Program Files (x86)/taglib/include/taglib/tstringlist.h;C:/Program Files (x86)/taglib/include/taglib/tbytevector.h;C:/Program Files (x86)/taglib/include/taglib/tbytevectorlist.h;C:/Program Files (x86)/taglib/include/taglib/tbytevectorstream.h;C:/Program Files (x86)/taglib/include/taglib/tiostream.h;C:/Program Files (x86)/taglib/include/taglib/tfile.h;C:/Program Files (x86)/taglib/include/taglib/tfilestream.h;C:/Program Files (x86)/taglib/include/taglib/tmap.h;C:/Program Files (x86)/taglib/include/taglib/tmap.tcc;C:/Program Files (x86)/taglib/include/taglib/tpropertymap.h;C:/Program Files (x86)/taglib/include/taglib/trefcounter.h;C:/Program Files (x86)/taglib/include/taglib/tdebuglistener.h;C:/Program Files (x86)/taglib/include/taglib/mpegfile.h;C:/Program Files (x86)/taglib/include/taglib/mpegproperties.h;C:/Program Files (x86)/taglib/include/taglib/mpegheader.h;C:/Program Files (x86)/taglib/include/taglib/xingheader.h;C:/Program Files (x86)/taglib/include/taglib/id3v1tag.h;C:/Program Files (x86)/taglib/include/taglib/id3v1genres.h;C:/Program Files (x86)/taglib/include/taglib/id3v2extendedheader.h;C:/Program Files (x86)/taglib/include/taglib/id3v2frame.h;C:/Program Files (x86)/taglib/include/taglib/id3v2header.h;C:/Program Files (x86)/taglib/include/taglib/id3v2synchdata.h;C:/Program Files (x86)/taglib/include/taglib/id3v2footer.h;C:/Program Files (x86)/taglib/include/taglib/id3v2framefactory.h;C:/Program Files (x86)/taglib/include/taglib/id3v2tag.h;C:/Program Files (x86)/taglib/include/taglib/attachedpictureframe.h;C:/Program Files (x86)/taglib/include/taglib/commentsframe.h;C:/Program Files (x86)/taglib/include/taglib/eventtimingcodesframe.h;C:/Program Files (x86)/taglib/include/taglib/generalencapsulatedobjectframe.h;C:/Program Files (x86)/taglib/include/taglib/ownershipframe.h;C:/Program Files (x86)/taglib/include/taglib/popularimeterframe.h;C:/Program Files (x86)/taglib/include/taglib/privateframe.h;C:/Program Files (x86)/taglib/include/taglib/relativevolumeframe.h;C:/Program Files (x86)/taglib/include/taglib/synchronizedlyricsframe.h;C:/Program Files (x86)/taglib/include/taglib/textidentificationframe.h;C:/Program Files (x86)/taglib/include/taglib/uniquefileidentifierframe.h;C:/Program Files (x86)/taglib/include/taglib/unknownframe.h;C:/Program Files (x86)/taglib/include/taglib/unsynchronizedlyricsframe.h;C:/Program Files (x86)/taglib/include/taglib/urllinkframe.h;C:/Program Files (x86)/taglib/include/taglib/chapterframe.h;C:/Program Files (x86)/taglib/include/taglib/tableofcontentsframe.h;C:/Program Files (x86)/taglib/include/taglib/podcastframe.h;C:/Program Files (x86)/taglib/include/taglib/oggfile.h;C:/Program Files (x86)/taglib/include/taglib/oggpage.h;C:/Program Files (x86)/taglib/include/taglib/oggpageheader.h;C:/Program Files (x86)/taglib/include/taglib/xiphcomment.h;C:/Program Files (x86)/taglib/include/taglib/vorbisfile.h;C:/Program Files (x86)/taglib/include/taglib/vorbisproperties.h;C:/Program Files (x86)/taglib/include/taglib/oggflacfile.h;C:/Program Files (x86)/taglib/include/taglib/speexfile.h;C:/Program Files (x86)/taglib/include/taglib/speexproperties.h;C:/Program Files (x86)/taglib/include/taglib/opusfile.h;C:/Program Files (x86)/taglib/include/taglib/opusproperties.h;C:/Program Files (x86)/taglib/include/taglib/flacfile.h;C:/Program Files (x86)/taglib/include/taglib/flacpicture.h;C:/Program Files (x86)/taglib/include/taglib/flacproperties.h;C:/Program Files (x86)/taglib/include/taglib/flacmetadatablock.h;C:/Program Files (x86)/taglib/include/taglib/apefile.h;C:/Program Files (x86)/taglib/include/taglib/apeproperties.h;C:/Program Files (x86)/taglib/include/taglib/apetag.h;C:/Program Files (x86)/taglib/include/taglib/apefooter.h;C:/Program Files (x86)/taglib/include/taglib/apeitem.h;C:/Program Files (x86)/taglib/include/taglib/mpcfile.h;C:/Program Files (x86)/taglib/include/taglib/mpcproperties.h;C:/Program Files (x86)/taglib/include/taglib/wavpackfile.h;C:/Program Files (x86)/taglib/include/taglib/wavpackproperties.h;C:/Program Files (x86)/taglib/include/taglib/trueaudiofile.h;C:/Program Files (x86)/taglib/include/taglib/trueaudioproperties.h;C:/Program Files (x86)/taglib/include/taglib/rifffile.h;C:/Program Files (x86)/taglib/include/taglib/aifffile.h;C:/Program Files (x86)/taglib/include/taglib/aiffproperties.h;C:/Program Files (x86)/taglib/include/taglib/wavfile.h;C:/Program Files (x86)/taglib/include/taglib/wavproperties.h;C:/Program Files (x86)/taglib/include/taglib/infotag.h;C:/Program Files (x86)/taglib/include/taglib/asffile.h;C:/Program Files (x86)/taglib/include/taglib/asfproperties.h;C:/Program Files (x86)/taglib/include/taglib/asftag.h;C:/Program Files (x86)/taglib/include/taglib/asfattribute.h;C:/Program Files (x86)/taglib/include/taglib/asfpicture.h;C:/Program Files (x86)/taglib/include/taglib/mp4file.h;C:/Program Files (x86)/taglib/include/taglib/mp4atom.h;C:/Program Files (x86)/taglib/include/taglib/mp4tag.h;C:/Program Files (x86)/taglib/include/taglib/mp4item.h;C:/Program Files (x86)/taglib/include/taglib/mp4properties.h;C:/Program Files (x86)/taglib/include/taglib/mp4coverart.h;C:/Program Files (x86)/taglib/include/taglib/modfilebase.h;C:/Program Files (x86)/taglib/include/taglib/modfile.h;C:/Program Files (x86)/taglib/include/taglib/modtag.h;C:/Program Files (x86)/taglib/include/taglib/modproperties.h;C:/Program Files (x86)/taglib/include/taglib/itfile.h;C:/Program Files (x86)/taglib/include/taglib/itproperties.h;C:/Program Files (x86)/taglib/include/taglib/s3mfile.h;C:/Program Files (x86)/taglib/include/taglib/s3mproperties.h;C:/Program Files (x86)/taglib/include/taglib/xmfile.h;C:/Program Files (x86)/taglib/include/taglib/xmproperties.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files (x86)/taglib/include/taglib" TYPE FILE FILES
    "D:/MyItems/taglib/taglib/tag.h"
    "D:/MyItems/taglib/taglib/fileref.h"
    "D:/MyItems/taglib/taglib/audioproperties.h"
    "D:/MyItems/taglib/taglib/taglib_export.h"
    "D:/MyItems/taglib/taglib/../taglib_config.h"
    "D:/MyItems/taglib/taglib/toolkit/taglib.h"
    "D:/MyItems/taglib/taglib/toolkit/tstring.h"
    "D:/MyItems/taglib/taglib/toolkit/tlist.h"
    "D:/MyItems/taglib/taglib/toolkit/tlist.tcc"
    "D:/MyItems/taglib/taglib/toolkit/tstringlist.h"
    "D:/MyItems/taglib/taglib/toolkit/tbytevector.h"
    "D:/MyItems/taglib/taglib/toolkit/tbytevectorlist.h"
    "D:/MyItems/taglib/taglib/toolkit/tbytevectorstream.h"
    "D:/MyItems/taglib/taglib/toolkit/tiostream.h"
    "D:/MyItems/taglib/taglib/toolkit/tfile.h"
    "D:/MyItems/taglib/taglib/toolkit/tfilestream.h"
    "D:/MyItems/taglib/taglib/toolkit/tmap.h"
    "D:/MyItems/taglib/taglib/toolkit/tmap.tcc"
    "D:/MyItems/taglib/taglib/toolkit/tpropertymap.h"
    "D:/MyItems/taglib/taglib/toolkit/trefcounter.h"
    "D:/MyItems/taglib/taglib/toolkit/tdebuglistener.h"
    "D:/MyItems/taglib/taglib/mpeg/mpegfile.h"
    "D:/MyItems/taglib/taglib/mpeg/mpegproperties.h"
    "D:/MyItems/taglib/taglib/mpeg/mpegheader.h"
    "D:/MyItems/taglib/taglib/mpeg/xingheader.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v1/id3v1tag.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v1/id3v1genres.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2frame.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2header.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2synchdata.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2footer.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2framefactory.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/id3v2tag.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/commentsframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/privateframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/unknownframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/chapterframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "D:/MyItems/taglib/taglib/mpeg/id3v2/frames/podcastframe.h"
    "D:/MyItems/taglib/taglib/ogg/oggfile.h"
    "D:/MyItems/taglib/taglib/ogg/oggpage.h"
    "D:/MyItems/taglib/taglib/ogg/oggpageheader.h"
    "D:/MyItems/taglib/taglib/ogg/xiphcomment.h"
    "D:/MyItems/taglib/taglib/ogg/vorbis/vorbisfile.h"
    "D:/MyItems/taglib/taglib/ogg/vorbis/vorbisproperties.h"
    "D:/MyItems/taglib/taglib/ogg/flac/oggflacfile.h"
    "D:/MyItems/taglib/taglib/ogg/speex/speexfile.h"
    "D:/MyItems/taglib/taglib/ogg/speex/speexproperties.h"
    "D:/MyItems/taglib/taglib/ogg/opus/opusfile.h"
    "D:/MyItems/taglib/taglib/ogg/opus/opusproperties.h"
    "D:/MyItems/taglib/taglib/flac/flacfile.h"
    "D:/MyItems/taglib/taglib/flac/flacpicture.h"
    "D:/MyItems/taglib/taglib/flac/flacproperties.h"
    "D:/MyItems/taglib/taglib/flac/flacmetadatablock.h"
    "D:/MyItems/taglib/taglib/ape/apefile.h"
    "D:/MyItems/taglib/taglib/ape/apeproperties.h"
    "D:/MyItems/taglib/taglib/ape/apetag.h"
    "D:/MyItems/taglib/taglib/ape/apefooter.h"
    "D:/MyItems/taglib/taglib/ape/apeitem.h"
    "D:/MyItems/taglib/taglib/mpc/mpcfile.h"
    "D:/MyItems/taglib/taglib/mpc/mpcproperties.h"
    "D:/MyItems/taglib/taglib/wavpack/wavpackfile.h"
    "D:/MyItems/taglib/taglib/wavpack/wavpackproperties.h"
    "D:/MyItems/taglib/taglib/trueaudio/trueaudiofile.h"
    "D:/MyItems/taglib/taglib/trueaudio/trueaudioproperties.h"
    "D:/MyItems/taglib/taglib/riff/rifffile.h"
    "D:/MyItems/taglib/taglib/riff/aiff/aifffile.h"
    "D:/MyItems/taglib/taglib/riff/aiff/aiffproperties.h"
    "D:/MyItems/taglib/taglib/riff/wav/wavfile.h"
    "D:/MyItems/taglib/taglib/riff/wav/wavproperties.h"
    "D:/MyItems/taglib/taglib/riff/wav/infotag.h"
    "D:/MyItems/taglib/taglib/asf/asffile.h"
    "D:/MyItems/taglib/taglib/asf/asfproperties.h"
    "D:/MyItems/taglib/taglib/asf/asftag.h"
    "D:/MyItems/taglib/taglib/asf/asfattribute.h"
    "D:/MyItems/taglib/taglib/asf/asfpicture.h"
    "D:/MyItems/taglib/taglib/mp4/mp4file.h"
    "D:/MyItems/taglib/taglib/mp4/mp4atom.h"
    "D:/MyItems/taglib/taglib/mp4/mp4tag.h"
    "D:/MyItems/taglib/taglib/mp4/mp4item.h"
    "D:/MyItems/taglib/taglib/mp4/mp4properties.h"
    "D:/MyItems/taglib/taglib/mp4/mp4coverart.h"
    "D:/MyItems/taglib/taglib/mod/modfilebase.h"
    "D:/MyItems/taglib/taglib/mod/modfile.h"
    "D:/MyItems/taglib/taglib/mod/modtag.h"
    "D:/MyItems/taglib/taglib/mod/modproperties.h"
    "D:/MyItems/taglib/taglib/it/itfile.h"
    "D:/MyItems/taglib/taglib/it/itproperties.h"
    "D:/MyItems/taglib/taglib/s3m/s3mfile.h"
    "D:/MyItems/taglib/taglib/s3m/s3mproperties.h"
    "D:/MyItems/taglib/taglib/xm/xmfile.h"
    "D:/MyItems/taglib/taglib/xm/xmproperties.h"
    )
endif()

