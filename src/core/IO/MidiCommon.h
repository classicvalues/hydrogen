/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 * Copyright(c) 2008-2023 The hydrogen development team [hydrogen-devel@lists.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see https://www.gnu.org/licenses
 *
 */

#ifndef H2_MIDI_COMMON_H
#define H2_MIDI_COMMON_H

#include <core/config.h>
#include <core/Object.h>
#include <string>
#include <vector>

#include <QString>

namespace H2Core
{

/** \ingroup docCore docMIDI */
class MidiMessage
{
public:
	enum MidiMessageType {
		UNKNOWN,
		SYSEX,
		NOTE_ON,
		NOTE_OFF,
		POLYPHONIC_KEY_PRESSURE,
		CONTROL_CHANGE,
		PROGRAM_CHANGE,
		CHANNEL_PRESSURE,
		PITCH_WHEEL,
		START,
		CONTINUE,
		STOP,
		SONG_POS,
		QUARTER_FRAME,
		SONG_SELECT,
		TUNE_REQUEST,
		TIMING_CLOCK,
		ACTIVE_SENSING,
		RESET
	};
	static QString TypeToQString( MidiMessageType type );

	MidiMessageType m_type;
	int m_nData1;
	int m_nData2;
	int m_nChannel;
	std::vector<unsigned char> m_sysexData;

	MidiMessage()
			: m_type( UNKNOWN )
			, m_nData1( -1 )
			, m_nData2( -1 )
			, m_nChannel( -1 ) {}

	/** Reset message */
	void clear();

	/**
	 * Derives and set #m_type (and if applicable #m_nChannel) using
	 * the @a statusByte of an incoming MIDI message. The particular
	 * values are defined by the MIDI standard and do not dependent on
	 * the individual drivers.
	 */
	void setType( int nStatusByte );

	/** Formatted string version for debugging purposes.
	 * \param sPrefix String prefix which will be added in front of
	 *   every new line
	 * \param bShort Instead of the whole content of all classes
	 *   stored as members just a single unique identifier will be
	 *   displayed without line breaks.
	 *
	 * \return String presentation of current object.*/
	QString toQString( const QString& sPrefix = "", bool bShort = true ) const;
};
};

#endif

