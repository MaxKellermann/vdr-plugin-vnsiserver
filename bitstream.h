/*
 *      vdr-plugin-vnsi - KODI server plugin for VDR
 *
 *      Copyright (C) 2010 Alwin Esch (Team XBMC)
 *      Copyright (C) 2015 Team KODI
 *
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with KODI; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef VNSI_BITSTREAM_H
#define VNSI_BITSTREAM_H

class cBitstream
{
private:
  uint8_t *m_data;
  int      m_offset;
  int      m_len;
  bool     m_error;

public:
  cBitstream(uint8_t *data, int bits);

  void         setBitstream(uint8_t *data, int bits);
  void         skipBits(int num);
  unsigned int readBits(int num);
  unsigned int showBits(int num);
  unsigned int readBits1() { return readBits(1); }
  unsigned int readGolombUE(int maxbits = 32);
  signed int   readGolombSE();
  unsigned int remainingBits();
  void         putBits(int val, int num);
  int          length() { return m_len; }
  bool         isError() { return m_error; }
};

#endif // VNSI_BITSTREAM_H
