mapping bonuses;
mapping dam_types;

query_special_slayer(string str) {
  switch(str) {
  case "demon": return 1;
  case "dragon": return 1;
  case "animal": return 1;
  }
}

query_bonus(string bonus, int number) {
  if(bonus == "hpregen") return number;
  if(bonus == "spregen") return number;
  return 0;
}

/* class 1-9 */
query_class_adjective(int class) {
  string str;
  int s;
  s = class;
  if(!class) return " wooden";
  str = "";
  if(s/3*3 == s) str = " fine";
  if(s < 4) str = " bronze";
  else if(s < 7) str += " iron";
  else if(s < 10) str += " steel";
  else if(s < 13) str += " mithril";
  return str;
}

valid_type(type) {
  if(type == "club") return 1; /*nuija*/
  if(type == "staff") return 1; /* sauva */
  if(type == "mace") return 1; /*piikkinuija*/
  if(type == "morningstar") return 1; /*ketju ja pallo*/
  if(type == "maul") return 1; /*leka*/
  if(type == "flail") return 1; /*isompi kuin mstar*/
  if(type == "warhammer") return 1; /*sotavasara*/

  if(type == "hatchet") return 2; /*puunhakkuukirves?*/
  if(type == "hand axe") return 2; /*kasikirves*/
  if(type == "broad axe") return 2; /*leveakirves*/
  if(type == "battle axe") return 2; /*sotakirves*/
  if(type == "two-edged axe") return 2; /*2teranen kirves*/
  if(type == "great axe") return 2; /*isokirves*/

  if(type == "dagger") return 3; /*tikari*/
  if(type == "short sword") return 3; /*lyhytmiekka*/
  if(type == "scimitar") return 3; /*sapeli*/
  if(type == "long sword") return 3; /*pitkamiekka*/
  if(type == "claymore") return 3; /*skottimiekka*/
  if(type == "broad sword") return 3; /*leveamiekka*/
  
if(type == "small shield") return 4;
  if(type == "medium shield") return 4;
  if(type == "large shield") return 4;

  if(type == "Shining mithril combat knuckles {10.Gup}") return 5; /*White*/
  if(type == "Shining mithril combat knuckles {8.Gup}") return 5; /* yellow */
  if(type == "Shining mithril combat knuckles {6.Gup}") return 5; /*green*/
  if(type == "Shining mithril combat knuckles {4.Gup}") return 5; /*blue*/
  if(type == "Shining mithril combat knuckles {2.Gup}") return 5; /*red*/
  if(type == "Shining mithril combat knuckles {I.DAN}") return 5; /*1.Dan*/
  if(type == "Shining mithril combat knuckles {IX.DAN}") return 5; /*9.dan*/


}

/* joka sub typella on eri +hit ja +damage  */
/* 3 eri damaa. bash, slash ja pierce */

query_hit_bonus(string arg,arg2) {
  int tmp,tmp2;
  string str;
  str = bonuses[arg];
  if(!str) return -1;
  if(sscanf(str, "%d %d",tmp,tmp2) != 2) {
    write("Error in weapon sub type data!\n");
    return -1;
  } else {
    if(arg2) return tmp2;
    return tmp;
  }
}
query_damage_bonus(arg) {
  return query_hit_bonus(arg,1);
}

query_damage_amount(string weapon, string type) {
  int bash, slash, pierce;
  string str;
  str = dam_types[weapon];
  if(!str) return -1;
  if(sscanf(str, "%d %d %d", bash, slash, pierce) != 3) {
    write("Error in weapon sub type damage data!\n");
    return -1;
  } else {
    if(type == "bash") return bash;
    if(type == "slash") return slash;
    if(type == "pierce") return pierce;
    write("query_damage_amount(string weapon, string type) [Error in argument 2!]\n");
  }
}

/* dam_types = [0, 100] */
/* bash, slash, pierce */

reset(arg) {
  if(arg) return;
  dam_types = ([ ]);

  dam_types += (["club":"100 0 0"]);
  dam_types += (["staff":"100 0 0"]);
  dam_types += (["mace":"90 0 10"]);
  dam_types += (["morningstar":"80 0 20"]);
  dam_types += (["maul":"100 0 0"]);
  dam_types += (["flail":"70 0 30"]);
  dam_types += (["warhammer":"100 0 0"]);

  dam_types += (["hatchet":"40 60 0"]);
  dam_types += (["hand axe":"40 60 0"]);
  dam_types += (["broad axe":"50 50 0"]);
  dam_types += (["battle axe":"40 40 20"]);
  dam_types += (["two-edged axe":"30 70 0"]);
  dam_types += (["great axe":"50 50 0"]);

  dam_types += (["dagger":"0 10 90"]);
  dam_types += (["short sword":"0 50 50"]);
  dam_types += (["scimitar":"0 100 0"]);
  dam_types += (["long sword":"10 70 20"]);
  dam_types += (["claymore":"30 60 10"]);
  dam_types += (["broad sword":"30 70 0"]);


  dam_types += (["Shining mithril combat knuckles {10.Gup}":"40 60 0"]);
  dam_types += (["Shining mithril combat knuckles {8.Gup}":"50 50 0"]);
  dam_types += (["Shining mithril combat knuckles {6.Gup}":"40 60 0"]);
  dam_types += (["Shining mithril combat knuckles {4.Gup}":"50 50 0"]);
  dam_types += (["Shining mithril combat knuckles {2.Gup}":"40 40 20"]);
  dam_types += (["Shining mithril combat knuckles {I.DAN}":"30 70 0"]);
  dam_types += (["Shining mithril combat knuckles {IX.DAN}":"50 50 0"]);
  /* hb [-2,2] , db [1,9]. */
  /* the weapon subtype classes are not comparable with each other */
  bonuses = ([ ]);
  bonuses += (["staff":"2 1"]);
  bonuses += (["club":"0 2"]);
  bonuses += (["mace":"1 3"]);
  bonuses += (["warhammer":"1 5"]);
  bonuses += (["maul":"0 6"]);
  bonuses += (["morningstar":"-1 7"]);
  bonuses += (["flail":"-2 9"]);

  bonuses += (["hatchet":"2 1"]);
  bonuses += (["hand axe":"1 2"]);
  bonuses += (["broad axe":"-1 4"]);
  bonuses += (["battle axe":"0 6"]);
  bonuses += (["two-edged axe":"-1 7"]);
  bonuses += (["great axe":"-2 9"]);

  bonuses += (["dagger":"2 1"]);
  bonuses += (["short sword":"1 2"]);
  bonuses += (["scimitar":"-1 4"]);
  bonuses += (["long sword":"0 5"]);
  bonuses += (["claymore":"-2 7"]);
  bonuses += (["broad sword":"-2 9"]);

  bonuses += (["Shining mithril combat knuckles {10.Gup}":"2 1"]);
  bonuses += (["Shining mithril combat knuckles {8.Gup}":"0 2"]);
  bonuses += (["Shining mithril combat knuckles {6.Gup}":"1 3"]);
  bonuses += (["Shining mithril combat knuckles {4.Gup}":"1 5"]);
  bonuses += (["Shining mithril combat knuckles {2.Gup} ":"0 6"]);
  bonuses += (["Shining mithril combat knuckles {I.DAN}":"-1 7"]);
  bonuses += (["Shining mithril combat knuckles {IX.DAN}":"-2 9"]);

  bonuses += (["small shield" :"-2 1"]);
  bonuses += (["medium shield":"0 5"]);
  bonuses += (["large shield" :"2 9"]);

}

get_long_desc(object weapon) {
  string type;
  type = weapon->query_sub_type();
  if(!valid_type(type)) return 0;
  switch(type) {
  case "small shield": return
"This is a small shield, plain and simple. Nothing very\n"+
"special about it. It would barely cover your underarm.\n";
  case "medium shield": return
"This is a medium sized shield. It's edges are reinforced with\n"+
"strong metal. It is big enough to grant sufficient cover to a fighter.\n";
  case "large shield": return
"A large shield is made to keep it's wearer alive and well in the most\n"+
"lethal situations. It covers an average human from the knees to the neck.\n"+
"It's shape is rectangular and it's bent a bit from the sides.\n"+
"The very bulk of shield is so big, that it can stop any blow.\n";
  case "club": return
"The club is little more than a cut-off tree branch. It has some rough\n"+
"spots, one might get small sticks into one's hand. The club has no\n"+
"special form, it's just a big stick used for blunting foes.\n";
  case "staff": return
"A wooden staff is made of a branch of some tree. Staves do not make\n"+
"very good weapons because of their light weight.\n";
  case "mace": return
"The mace is a tool, an advanced version of a club. The haft is smooth,\n"+
"all rough spots have been worked away. It has a specified handle.\n"+
"Some metal reinforcements have been done to the end of the weapon,\n"+
"three spikes point out of the surface.\n";
  case "flail": return
"The flail is the most devastating weapon available. It is the choise of\n"+
"sadists and fanatics. A quite long haft is attached to a chain that end\n"+
"to a spiked metal ball. It is not used to simply kill somebody, but to\n"+
"pierce, bash and torn his flesh. If well used, it leaves behind nothing\n"+
"but mutilated slumps of flesh and bone.\n";
  case "morningstar": return
"The morningstar is like it's bigger version, flail, but smaller.\n"+
"It is easier to use and it won't tear it's user if used inexperiencedly.\n"+
"It's prefered by many mounted warriors who like to use shield in their\n"+
"other hand. A small haft is attached to a chain that end to a spiked\n"+
"metal ball. The spikes are not very big and the ball is not as devastating\n"+
"as in a flail.\n";
  case "warhammer": return
"The warhammer is made completely of metal alloy. A strong thick haft\n"+
"ends into a solid cube of cold metal. The krushing effect of this weapon is\n"+
"quite destructive. It's a good example of the new weapon craft.\n";
  case "maul": return
"The maul is a very simple weapon. A long haft is attached into a large\n"+
"cube of cold metal. No armour can protect the target from the utterly\n"+
"devastating effect of the horrible force when the maul is swung.\n"+
"While warhammer is used to hurt, this item is used to kill.\n";
case "hatchet": return
"The hatchet is used to chop logs. It is also used by butchers for cutting\n"+
"the meat. It is easy to use, but not much for a weapon.\n";
  case "hand axe": return
"The handaxe is a bigger version of the hatchet. It's mostly used by\n"+
"lumberjacks for cutting trees down. It's a typical axe.\n";
  case "broad axe": return
"The broad axe has a large and heavy edge. It is not very accurate weapon,\n"+
"but gets the job done. It's too heavy to be used for woodcutting.\n";
  case "battle axe": return
"The battle axe is designed for the purpose of killing living creatures.\n"+
"When it lands on the victim, the blow is meant to kill. The axe itself\n"+
"is not very different of a hand axe. The blade is wider and the haft\n"+
"is longer.\n";
  case "two-edged axe": return
"The two-edged axe is a mighty weapon. It's useful when swinging back and\n"+
"forth in the heat of battle. Otherwise is quite the same as the battle axe;\n"+
"the blade is quite wide and the haft is long.\n";
  case "great axe": return
"The great axe is nothing but a huge version of the battle axe. It is designed\n"+
"to be used by big creatures.\n";
  case "dagger": return
"The dagger is the smallest of blade type weapons. A small handle\n"+
"ends to the short metal blade. It's easy to use, but not very deadly.\n";
  case "short sword": return
"The short sword is a simple weapon. A handle meant for one hand\n"+
"is attached into the short blade. The blade has two edges and it's\n"+
"an easy weapon to use.\n";
  case "scimitar": return
"The scimitar has the length of a sword though it's blade is bent\n"+
"backwards and it has a better slashing effect than a normal sword.\n";
  case "sabre": return
"The sabre is somewhat thinner than a normal sword. This increases\n"+
"it's piercing capabilities.\n";
  case "long sword": return
"The long sword is a basic sword. It's two-edged blade long and quite thin.";
  case "claymore": return
"The claymore is longer than a long sword and it's blade is thicker.";
  case "broad sword": return
"The broad sword is used by strong warriors. It's strong blade is meant to\n"+
"endure great force. The sword is the biggest and heaviest sword available.\n";
  }
}

