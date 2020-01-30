spell_categories(word) {
  if (word == "exs") { return 1; }
  if (word == "chl") { return 1; }
  if (word == "doo") { return 1; }
  if (word == "dcs") { return 1; }
  if(word == "kyo") return 1;
}

get_text(string word) {
  int i;
  switch(word) {
  case "fla":return "You concentrate your mind on the heat of flames and mumble the word: 'fla'\n";
  case "brr":return "You concentrate your mind on the coldness of ice and mumble the word: 'brr'\n";
  case "zzt":return "You think about thunder and the power of a lightning while pronouncing: 'zzt'\n";
  case "poi":return "You concentrate your mind on the sweet taste of poisons and mumble the word: 'poi'\n";
  case "sol":return "You feel the earth under your feet and shout: 'SOL!'\n";
  case "cre":return "You end the spell with a creative gesture and mutter the word: 'Cre'\n";
  case "huh":return "With a stupid look on your face you utter the magical word: 'HUH?'\n";
  case "trn":return "You get a far away look in your eyes and mumble the word: 'trn'\n";
  case "zum":return "You focus your thoughts, close your eyes and state: 'zum'\n";
  case "ils":return "You grin wickedly and mumble: 'ils'\n";
  case "mdr":return "You get a hungry look on your face and yell: 'mdr'\n";
  case "zas":return "You close your eyes and mumble: 'zas'\n";
  }
  i = random(3);
  switch(i) {
  case 0: return "You mumble the magic word: '" + word + "'\n";
  case 1: return "You focus your thoughts and whisper: '"+word+"'\n";
  case 2: return "You concentrate very hard ignoring everything around you and chant: '"+word+"'\n";
  }
}

get_sub_text(string word) {
  switch(word) {
  case "cre": return "looks creative and mumbles the magic word:";
  case "fla": return "looks quite mad while uttering the magic word:";
  case "brr": return "shivers and mumbles:";
  case "poi": return "grins evilly and yells the magic word:";
  case "zzt": return "looks shocked and says the magic word:";
  case "sol": return "looks at the ground and shouts:";
  case "huh": return "stupidly utters:";
  case "trn": return "gets an empty look and whispers:";
  case "zum": return "seems to concentrate very hard and mumbles:";
  case "ils": return "grins wickedly and mumbles:";
  case "mdr": return "gets an hungry look and yells:";
  case "zas": return "concentrates and states:";
  }
}

get_text_to_others(string word, object who) {
   string str;
  str = get_sub_text(word);
  if(!who)who=this_player();
  if(str) {
    str = who->query_name()+" "+str+" '"+word+"'\n";
  } else {
    str = who->query_name() + " mumbles the magic word: '" + word + "'\n";
  }
  return str;
}


get_skill_num(string word) {
  switch(word) {
  case "exs": return "cast essence";
  case "fla": return "cast fire";
  case "brr": return "cast ice";
  case "sol": return "cast earth";
  case "zzt": return "cast electric";
  case "blt": return "cast bolt";
  case "strm": return "cast storm";
  case "poi": return "cast poison";
  case "chl": return "cast divine";
  case "min": return "cast minor";
  case "les": return "cast lesser";
  case "mar": return "cast major";
  case "hea": return "cast heal";
  case "alg": return "cast alignment";
  case "num": return "cast cure";
  case "xfr": return "cast transfer";
  case "bls": return "cast bless";
  case "msh": return "cast minor protection";
  case "lsh": return "cast lesser protection";
  case "gsh": return "cast greater protection";
  case "blc": return "cast shielding";
  case "mir": return "cast mirror image";
  case "cre": return "cast create";
  case "rha": return "cast trade";
  case "trn": return "cast teleport";
  case "loc": return "cast locate";
  case "rel": return "cast relocate";
  case "eth": return "cast soul";
  case "res": return "cast resurrect";
  case "rnc": return "cast reincarnation";
  case "alr": return "cast holy alteration";
  case "sex": return "cast gender";
  case "kfq": return "cast wide";
  case "nam": return "cast satisfy";
  case "arr": return "cast arrow";
  case "grsp": return "cast grasp";
  case "tel": return "cast return";
  case "hre": return "cast summon";
  case "mdr": return "cast mana drain";

  case "huh": return "cast information";
  case "eep": return "cast item";
  case "rmv": return "cast remove";
  case "scr": return "cast scar";
  case "hrm": return "cast harm";
  case "bsw": return "cast grant";
  case "rgn": return "cast regeneration";
  case "enp": return "cast durability";
  case "snp": return "cast mana";
  case "hnp": return "cast endurance";
  case "uuo": return "cast life";
  case "hmm": return "cast invisibility";
  case "ahm": return "cast see invisibility";
  case "ils": return "cast illusion";
  case "zum": return "cast force field";

  case "doo": return "cast dark power";
  case "naa": return "cast raise corporeal";
  case "nii": return "cast raise ethereal";
  case "nuu": return "cast unholy enchantment";
  case "noo": return "cast focus dark power";
  case "maa": return "cast minor necromancy";
  case "moo": return "cast major necromancy";
  case "muu": return "cast supreme necromancy";
  case "nee": return "cast raise soul";

  case "kyo": return "cast abjuration";
  case "tdr": return "cast alteration";
  case "jht": return "cast protection";
  case "rhj": return "cast vulnerability";
  case "yed": return "cast antimagic";
  case "dio": return "cast sorcery";
  case "cvk": return "cast enchantment";
  case "zas": return "cast force";

  case "ooo": return "call angel";
//Warlock
  case "dcs": return "cast plane of chaos";
  case "aum": return "cast chaos sheltering";
  case "cad": return "cast beast control";
  case "cab": return "cast aid of chaos";
  case "cel": return "cast warmth of chaos";
  case "cwe": return "cast anvil of chaos";
  case "bcw": return "cast blessing of chaos";
  case "cpl": return "cast void travel";
  case "car": return "cast forge of chaos";
  case "rca": return "cast ritual of chaos";
  case "lec": return "cast lesser chaos";
  case "mic": return "cast minor chaos";
  case "grm": return "cast greater chaos";
  }
  return 0;
}

sp_cost(string word) {
  int cost;
 switch(word) {
  case "blt": return (50+this_player()->query_sp_boost(1));
  case "strm": return (300+this_player()->query_sp_boost(1));
  /* reducaa spta resolvessa */
  case "maa": return 1;
  case "moo": return 1;
  case "muu": return 1;
  case "cad": return this_player()->query_max_sp()/2;
  case "rca": return this_player()->query_max_sp()/4;
 }
  cost = sp_cost_base(word);
  /* jos ei oo costia, mutta tavu ja skilli sille on olemassa */
  if(!cost && get_skill_num(word))
        log_file("NO_SP_COST", ctime(time())+" Syllabe: "+word+" Caster: "+this_player()->query_name()+"\n");
  cost = cost*cost*10;
  return cost;
}

/* sp cost vakio suhteessa muihin tavuihin. [1,5] //Celtron */
sp_cost_base(string word) {
 switch(word) {
  case "exs": return 1;
  case "fla": return 1;
  case "brr": return 2;
  case "sol": return 1;
  case "zzt": return 2;
  case "poi": return 3;
  case "chl": return 1;
  case "min": return 1;
  case "les": return 3;
  case "mar": return 5;

  case "ooo": return 5;

  case "hea": return 2;
  case "alg": return 2;
  case "xfr": return 2;
  case "num": return 2;
  case "eth": return 5;
  case "bls": return 4;
  case "alr": return 3;
  case "kfq": return 3;
  case "nam": return 1;
  case "sex": return 5;

  case "ils": return 3;
  case "zum": return 4;
  case "cre": return 3;
  case "trn": return 2;
  case "loc": return 5;
  case "huh": return 3;
  case "rha": return 4;

  case "kyo": return 1;
  case "tdr": return 2;
  case "jht": return 4;
  case "rhj": return 3;
  case "cvk": return 3;
  case "mdr": return 6;
  case "zas": return 2;
  case "yed": return 5;
  case "dio": return 4;

  /* necro */
  case "doo": return 1+this_player()->query_level()/40;
  case "noo": return 2;
  case "naa": return 1;
  case "nii": return 3;
  case "nuu": return 4;
  /* reducaa spta resolvessa (do check) //Celtron */
  case "maa": return 1;
  case "moo": return 1;
  case "muu": return 1;
  case "nee": return 1;
  //warlock
    case "dcs": return 2;
    case "aum": return 3;
    case "cab": return 5;
    case "cel": return 2;
    case "cwe": return 5;
    case "bcw": return 8;
    case "cpl": return 5;
    case "car": return 8;
    case "lec": return 2;
    case "mic": return 4;
    case "grm": return 6;
 }
}
