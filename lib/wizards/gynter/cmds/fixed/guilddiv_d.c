/* This file calculates bonuses for a player */
#define ALPHA "/daemons/alpha"

mapping abjurer, mage, cleric, fighter, necromancer, psionicist, warlock, witch;

void reset(status arg) {
  if(arg) return;
            /* ATTENTION ATTENTION */
  /* PrimGuild should always be added first!! */
          /* ATTENTION ATTENTION */
  /* "GUILDNAME":STR;DEX;CON;INT;WIS */
  /* Add here if you have added a subguild */
  /* Add them in alfabetical order for easy to read */

  abjurer = ([
  "Abjurer":0;0;0;1;1,
  "Masters of Abjuration":0;0;0;0;1,
  "Masters of Sorcery":0;0;0;1;1,
  "Masters of Vulnerability":0;0;0;0;2
  ]);
  cleric = ([
  "Apprentice Cleric":0;0;1;0;1,
  "Adept Clerics":0;0;0;0;2,
  "High Clerics":0;0;0;0;2
  ]);
  fighter = ([
  "Fighter":1;0;1;0;0,
  "Acrobats":0;3;1;0;0,
  "Axers":1;0;1;0;0,
  "Barbarians":1;0;1;0;0,
  "Berserkers":1;0;1;0;0,
  "Blademasters":1;1;0;0;0,
  "Bludgeonists":2;0;0;0;0,
  "Body builders":2;2;2;2;2,
  "Defenders":0;1;1;0;0,
  "Ranger":0;1;3;0;0,
  "Smith":1;0;2;0;0,
  "Veterans":1;1;0;0;0,
  "Warriors":1;0;2;0;0,
  "Weapon Master":1;1;0;0;0
  ]);
  mage = ([
  "Apprentice Mages":0;0;0;2;0,
  "Advanced Mages":0;0;0;2;0,
  "Arcaners":0;0;-1;2;0,
  "Electricity School":0;0;0;2;0,
  "Fire School":0;0;0;2;0,
  "Ice School":0;0;0;2;0,
  "Illusionists":0;0;-1;2;0,
  "Master Mages":0;0;-1;2;0,
  "Merchants":0;0;0;1;1,
  "Navigators":0;0;0;2;0,
  "Poison School":0;0;0;2;0,
  "Scroll Scribblers":0;0;0;2;0
  ]);
  necromancer = ([
  "Necromancer":0;0;0;1;1,
  "Apprentice Controllers":0;0;0;2;0,
  "Adept Controllers":0;0;0;1;1,
  "Master Animators":0;0;0;2;0,
  "Necromancer Adepts":1;0;0;1;0,
  "Unholy Lords":0;0;0;1;1
  ]);
  psionicist = ([
  "Psionicist":0;0;1;0;1,
  "Emphatics":0;0;0;1;1,
  "Telekinetics":0;0;1;1;0
  ]);
  warlock = ([
  "Warlock":0;0;2;3;0,
  "Chaos Fighters":2;0;2;0;0,
  "Chaos Warlocks":1;0;1;0;0,
  "Grand Warlocks":0;0;2;3;0,
  "Initiate of Chaos":3;0;0;1;0,
  "Master Warlocks":0;0;2;2;0
  ]);
  witch = ([
  "Witch":0;0;0;2;3
  ]);
}

//checking what subs..
check_subs(mapping arg) {
  string *subs, *dump_map, spaces, guild, level, bonus;
  int st, de, co, in, wi, lvls, i, j;
  // Fixing up m_indices for the arg mapping
  subs = m_indices(arg);
  subs = ALPHA->alpha(arg);
  dump_map = m_indices(arg);
  spaces = "                                             ";
  // Sorting and fixing
    j = 0;
    if(member(arg, "Abjurer")) {
      if(mapping_contains(&st,&de,&co,&in,&wi,abjurer,"Abjurer")) {
        lvls = arg["Abjurer"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Abjurer" + spaces[0..(strlen(spaces)-strlen("Abjurer")-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += "Abjurer" + lvls + st + de + co + in + wi;
        for(i = 0;i < sizeof(subs);i++) {
          if(mapping_contains(&st,&de,&co,&in,&wi,abjurer,subs[i])) {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))]+level+ "\n"+
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus + "\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Apprentice Cleric"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,cleric,"Apprentice Cleric"))
      {
        lvls = arg["Apprentice Cleric"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Apprentice Cleric" + spaces[0..(strlen(spaces)-strlen("Apprentice Cleric")-strlen(level))] + level + "\n" +
                              spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        write(dump_map[j-1]+"\n");
        write(level + bonus +"\n");
        // dump_map += ([ "Apprentice Cleric" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,cleric,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Fighter"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,fighter,"Fighter"))
      {
        lvls = arg["Fighter"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Fighter" + spaces[0..(strlen(spaces)-strlen("Fighter")-strlen(level))] + level + "\n" +
                              spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += ([ "Fighter" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,fighter,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Apprentice Mages"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,mage,"Apprentice Mages"))
      {
        lvls = arg["Apprentice Mages"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Apprentice Mages" + spaces[0..(strlen(spaces)-strlen("Apprentice Mages")-strlen(level))] + level + "\n" +
                                spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += ([ "Apprentice Mages" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,mage,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Necromancer"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,necromancer,"Necromancer"))
      {
        lvls = arg["Necromancer"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Necromancer" + spaces[0..(strlen(spaces)-strlen("Necromancer")-strlen(level))] + level + "\n" +
                              spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += ([ "Necromancer" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,necromancer,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Psionicist"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,psionicist,"Psionicist"))
      {
        lvls = arg["Psionicist"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Psionicist" + spaces[0..(strlen(spaces)-strlen("Psionicist")-strlen(level))] + level + "\n" +
                                spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += ([ "Psionicist" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,psionicist,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Warlock"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,warlock,"Warlock"))
      {
        lvls = arg["Warlock"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Warlock" + spaces[0..(strlen(spaces)-strlen("Warlock")-strlen(level))] + level + "\n" +
                                spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += ([ "Warlock" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,warlock,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
    if(member(arg, "Witch"))
    {
      if(mapping_contains(&st,&de,&co,&in,&wi,witch,"Witch"))
      {
        lvls = arg["Witch"];
        st = st*lvls;
        de = de*lvls;
        co = co*lvls;
        in = in*lvls;
        wi = wi*lvls;
        level = "(lvl "+ lvls +")";
        bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
        dump_map[j] = "Witch" + spaces[0..(strlen(spaces)-strlen("Witch")-strlen(level))] + level + "\n" +
                                spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
        j++;
        // dump_map += ([ "Witch" : lvls ; st ; de ; co ; in ; wi ]);
        for(i = 0;i < sizeof(subs);i++)
        {
          if(mapping_contains(&st,&de,&co,&in,&wi,witch,subs[i]))
          {
            lvls = arg[subs[i]];
            st = st*lvls;
            de = de*lvls;
            co = co*lvls;
            in = in*lvls;
            wi = wi*lvls;
            level = "(lvl "+ lvls +")";
            bonus = "Bonus: Str["+ st +"], Dex["+ de +"], Con["+ co +"], Int["+ in +"], Wis["+ wi +"]";
            dump_map[j] = subs[i] + spaces[0..(strlen(spaces)-strlen(subs[i])-strlen(level))] + level + "\n" +
                                  spaces[0..(strlen(spaces)-strlen(bonus))] + bonus +"\n";
            j++;
            // dump_map += ([ subs[i] : lvls ; st ; de ; co ; in ; wi ]);
          }
        }
      }
    }
  return dump_map;
}