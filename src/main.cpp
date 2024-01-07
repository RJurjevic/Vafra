/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2023 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

#include "bitboard.h"
#include "endgame.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "uci.h"
#include "syzygy/tbprobe.h"

namespace PSQT {
  void init();
}

/*
  V 14.12.0
    - Stockfish 12 modified so to use flipped HalfKP 256x2-32-32-1 NNUE.
    - Used nn-562d1cf56c39.nnue NNUE aka nn-v0f000010003.nnue.
    - Quiet moves sort scoring updated as in Stockfish 16 by adding bonuses for checks and escaping from capture and malus for putting piece en prise.
    - In search Step 7 Razoring razoring implemented similarly as in Stockfish 16.
    - In search Step 11 Internal iterative deepening internal iterative deepening implemented similarly as in Stockfish 9 instead of if the position is not in TT decreasing the depth by 2.
    - In Step 16 Reduced depth search removed decreasing reduction if the ttHit running average is large.

  V 14.12.1
    - Used nn-7e7183aae9f7.nnue NNUE aka nn-v0f000010401.nnue.
*/

int main(int argc, char* argv[]) {

  std::cout << engine_info() << std::endl;

  CommandLine::init(argc, argv);
  UCI::init(Options);
  Tune::init();
  PSQT::init();
  Bitboards::init();
  Position::init();
  Bitbases::init();
  Endgames::init();
  Threads.set(size_t(Options["Threads"]));
  Search::clear(); // After threads are up
  Eval::init_NNUE();

  UCI::loop(argc, argv);

  Threads.set(0);
  return 0;
}
