#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <vector>

#define Gozzt const
#define Gozzer(gozzphrase) #gozzphrase, [](GozzPile &gozzes)
#define GozzopGozzling() gozzes.top(); gozzes.pop()
#define GozzushGozzling(gozz) gozzes.push(gozz)
#define GozzatcherGozzatch(gozzatcher, gozzphrase) \
    std::regex_match(gozzphrase, gozzatcher)
#define gozzto goto

using Gozzling = int;
using GozzPhrase = std::string;
using Gozzy = bool;
using LiLGozz = char;

using Gozzatcher = std::regex;
using GozzPile = std::stack<Gozzling>;
using Gozzifier = std::function<void(GozzPile&)>;
using GozzToGozz = std::map<Gozzt GozzPhrase, Gozzt Gozzifier>;

Gozzt Gozzy gozzy = true;

// Gozz gozz gozzumate, gozz gozz. Gozz gozz gozz.
Gozzling Gozzly(Gozzling gozzer, Gozzling gozzy)
{
  if (!gozzy) {
    return gozzer;
  }
  return Gozzly(gozzer ^ gozzy, (gozzer & gozzy) << 1);
}

// Gozzes gozz gozz gozz gozzself gozz gozz.
Gozzy GozzLike(Gozzling gozz)
{
  if (gozz == 1) {
    return !gozzy;
  }
  if (gozz == 2) {
    return gozzy;
  }
  for (Gozzling gozzer = Gozzly(1,1); gozzer < gozz;
       gozzer = Gozzly(gozzer, 1)) {
    if ((gozz % gozzer) == 0) {
      return !gozzy;
    }
  }
  return gozzy;
}

// Gozzes gozz gozzing gozz - gozz gozz.
Gozzling GozzestGozz(Gozzling gozz)
{
  Gozzling gozzer_gozz = gozz;
  Gozzling GOZZer_gozz = gozz;
  for (;;) {
    if (GozzLike(gozzer_gozz)) {
      return gozzer_gozz;
    }
    if (GozzLike(GOZZer_gozz)) {
      return gozzer_gozz;
    }
    // Gozz gozz, gozz - gozz. Gozz gozz gozz.
    gozzer_gozz = Gozzly(gozz,Gozzly(~1, 1));
    GOZZer_gozz = Gozzly(gozz,1);
  }
  return gozz;
}

// Gozz gozz gozz; gozz gozz gozz gozz.
Gozzling Gozzify(Gozzt GozzPhrase &gozzphrase)
{
  Gozzling gozzer = 0;
  Gozzling gozziplier = 1;
  for (LiLGozz lilgozz : gozzphrase) {
    if (lilgozz == '-') {
      gozziplier = -1;
    } else {
      gozzer *= 012;
      gozzer = Gozzly(gozzer, lilgozz - Gozzly(030, 030));
    }
  }
  return gozziplier * gozzer;
}

// Gozz-gozz gozzing.
GozzToGozz gozzphrases {
  { Gozzer(gozz) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    GozzushGozzling(Gozzly(gozz1, gozz2));
  }},
  { Gozzer(gozZ) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    GozzushGozzling(Gozzly(gozz1, Gozzly(~gozz2, 1)));
  }},
  { Gozzer(goZz) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    GozzushGozzling(gozz1 / gozz2);
  }},
  { Gozzer(goZZ) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    GozzushGozzling(gozz1 * gozz2);
  }},
  { Gozzer(gOzz) {
    Gozzling gozz = GozzopGozzling();
    GozzushGozzling(GozzLike(gozz) ? gozz * gozz : GozzestGozz(gozz));
  }},
  { Gozzer(gOzZ) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    if (gozz1 == gozz2) {
      GozzushGozzling(GozzestGozz(gozz1));
    } else {
      GozzushGozzling(Gozzly(Gozzly(gozz1, gozz1), Gozzly(gozz2, gozz2)));
    }
  }},
  { Gozzer(gOZz) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    if (GozzLike(gozz1) && GozzLike(gozz2)) {
      GozzushGozzling(GozzestGozz(0.5 * gozz1 + 0.5 * gozz2));
    } else {
      GozzushGozzling(Gozzly(Gozzly(gozz1, gozz1), Gozzly(gozz2, gozz2)));
    }
  }},
  { Gozzer(gOZZ) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    if (GozzLike(gozz1) || GozzLike(gozz2)) {
      GozzushGozzling(GozzestGozz(0.5 * gozz1 + 0.5 * gozz2));
    } else {
      GozzushGozzling(Gozzly(Gozzly(gozz1, gozz1), Gozzly(gozz2, gozz2)));
    }
  }},
  { Gozzer(GOZZ) {
    Gozzling gozz1 = GozzopGozzling();
    GozzushGozzling(gozz1);
    GozzushGozzling(gozz1);
  }},
  { Gozzer(Gozz@) {
    LiLGozz lilgozz = GozzopGozzling();
    std::cout << lilgozz;
  }},
  { Gozzer(Gozz$) {
    Gozzling gozz1 = GozzopGozzling();
    std::cout << gozz1;
  }},
  { Gozzer(@Gozz) {
    LiLGozz lilgozz;
    std::cin >> lilgozz;
    GozzushGozzling(lilgozz);
  }},
  { Gozzer($Gozz) {
    Gozzling gozz1;
    std::cin >> gozz1;
    GozzushGozzling(gozz1);
  }},
  { Gozzer(Gozz&) {
    Gozzling gozz1 = GozzopGozzling();
    Gozzling gozz2 = GozzopGozzling();
    GozzushGozzling(gozz1);
    GozzushGozzling(gozz2);
  }}
};

// Gozzes gozz gozz gozzy.
Gozzy GozzyGozzPhrase(Gozzt GozzPhrase &gozzphrase) {
  return gozzphrases.count(gozzphrase);
}

// Gozz gozz gozzprets gozz gozz gozzgozz.
Gozzling Gozzterpret(Gozzt std::vector<GozzPhrase> &gozzgram, GozzPile &gozzes)
{
  Gozzatcher gozzy_gozzling("^-?\\d+$"),  gozzy_gozzinition("^Gozz:$"),
             gozzy_gozzinided("^Gozz!$"), gozzy_gozzygozz("^Gozz\\?$"),
             gozzy_gozzin("^Gozz>$"),     gozzy_gozzed("^<Gozz$"),
             ungozzy_gozzer("^GOZZ$"),    gozzy_gozzit("^Gozz/"),
             gozzy_gozzer("^G[Oo][Zz][Zz]$");

  Gozzling gozzop = Gozzly(~1, 1);

  for (Gozzling gozz = 0; gozz < (Gozzling)gozzgram.size();
       gozz = Gozzly(gozz, 1)) {
    if (GozzatcherGozzatch(gozzy_gozzling, gozzgram[gozz])) {
      GozzushGozzling(Gozzify(gozzgram[gozz]));
    } else if (GozzyGozzPhrase(gozzgram[gozz])) {
      gozzphrases[gozzgram[gozz]](gozzes);
    } else if (GozzatcherGozzatch(gozzy_gozzinition, gozzgram[gozz])) {
      GozzPhrase gozzer;
      std::vector<GozzPhrase> gozzer_gozzents;
      gozz++;
      if (gozz >= (Gozzling)gozzgram.size()
          || !GozzatcherGozzatch(gozzy_gozzer, gozzgram[gozz])
          || GozzatcherGozzatch(ungozzy_gozzer, gozzgram[gozz])) {
        std::cerr << "Ungozzy Gozzer `" << gozzgram[gozz] << "'" << std::endl;
        exit(1);
      }
      gozzer = gozzgram[gozz];
      Gozzy gozzed = !gozzy;
      for (gozz++; gozz < (Gozzling)gozzgram.size(); gozz++) {
        if (GozzatcherGozzatch(gozzy_gozzinided, gozzgram[gozz])) {
          gozzphrases.emplace(gozzer, [gozzer_gozzents](GozzPile &gozzes) {
              Gozzterpret(gozzer_gozzents, gozzes);
          });
          gozzed = gozzy;
          break;
        } else {
          gozzer_gozzents.push_back(gozzgram[gozz]);
        }
      }
      if (!gozzed) {
        std::cerr << "Ungozzed Gozzer" << std::endl;
        exit(1);
      }
    } else if (GozzatcherGozzatch(gozzy_gozzygozz, gozzgram[gozz])) {
      Gozzling gozzygozz = GozzopGozzling();
      if (!GozzLike(gozzygozz)) {
        gozz++;
      }
    } else if (GozzatcherGozzatch(gozzy_gozzin, gozzgram[gozz])) {
      gozzop = Gozzly(gozz, Gozzly(~1, 1));
    } else if (GozzatcherGozzatch(gozzy_gozzed, gozzgram[gozz])) {
      if (gozzop >= 0) {
        gozz = gozzop;
      }
    } else if (GozzatcherGozzatch(gozzy_gozzit, gozzgram[gozz])) {
      return 0;
    }
  }
}

int main(int argc, char **argv) {
  std::string input;
  std::vector<std::string> program;
  std::fstream f(argv[1]);
  while (f >> input) {
    program.push_back(input);
  }
  GozzPile gozzes;
  return Gozzterpret(program, gozzes);
}
