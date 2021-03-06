/* 
   SESC: Super ESCalar simulator
   Copyright (C) 2003 University of Illinois.

   Contributed by Jose Renau

This file is part of SESC.

SESC is free software; you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation;
either version 2, or (at your option) any later version.

SESC is    distributed in the  hope that  it will  be  useful, but  WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should  have received a copy of  the GNU General  Public License along with
SESC; see the file COPYING.  If not, write to the  Free Software Foundation, 59
Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/


#include "VTaskHandler.h"
#include "HVersion.h"
#include "LVIDTable.h"

void VTaskHandler::kill(const HVersion *ver, bool inv)
{
  TaskHandler::kill(ver, inv);
  LVIDTable::kill(ver);
}

bool VTaskHandler::restart(const HVersion *ver)
{
  bool done = TaskHandler::restart(ver);

  if(!done)
    return false;

  LVIDTable::restart(ver);

  return true;
}

void VTaskHandler::setSafe(HVersion *ver)
{
  TaskHandler::setSafe(ver);
  LVIDTable::setSafe(ver);
}

void VTaskHandler::setFinished(HVersion *ver)
{
  TaskHandler::setFinished(ver);
  LVIDTable::setFinished(ver);
}
