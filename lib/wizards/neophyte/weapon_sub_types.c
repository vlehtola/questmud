mapping bonuses;
mapping dam_types;

query_special_slayer(string str) {
  switch(str) {
  case "demon": return 1;
  case "dragon": return 1;
  case "animal": return 1;
  }
}

/* class 1-9 */
query_class_adjective(int class) {
  switch(class) {
	  case 0: return "very poor";
	  case 1: return "poor";
	  case 2: return "loysy";
	  case 3: return "low";
	  case 4: return "below standard";
	  case 5: return "standard";
	  case 6: return "above standard";
	  case 7: return "quite good";
	  case 8: return "good";
	  case 9: return "great";
	  case 10: return "superb";
  }
  return "outstanding";
}

query_weapon_size(string type) {
		/*Bludgeons*/
	  if(type == "club") return 150;
	  if(type == "spiked club") return 170;
	  if(type == "staff") return 250;
	  if(type == "quarter staff") return 300;
	  if(type == "mace") return 250;
	  if(type == "morningstar") return 200;
	  if(type == "hammer") return 350;
	  if(type == "maul") return 400;
	  if(type == "flail") return 300;
	  if(type == "warhammer") return 450;
	  /*Axes*/
	    if(type == "hatchet") return 100;
	    if(type == "hand axe") return 250;
	    if(type == "head axe") return 400;
	    if(type == "field axe") return 350;
	    if(type == "bearded axe") return 650;
	    if(type == "broad axe") return 450;
	    if(type == "battle axe") return 600;
	    if(type == "two-edged axe") return 550;
	    if(type == "war axe") return 600;
	    if(type == "great axe") return 750;
		/*Sword*/
	  if(type == "dagger") return 50;
	  if(type == "short sword") return 70;
	  if(type == "sabre") return 40;
	  if(type == "scimitar") return 100;
	  if(type == "cutlass") return 150;
	  if(type == "long sword") return 240;
	  if(type == "broad sword") return 350;
	  if(type == "claymore") return 450;
	  if(type == "bastard sword") return 550;
	  if(type == "greatsword") return 600;
	  /*Shields*/
	  if(type == "buckler") return 150;
	  if(type == "small shield") return 110;
	  if(type == "spiked shield") return 150;
	  if(type == "knight shield") return 240;
	  if(type == "medium shield") return 250;
	  if(type == "kite shield") return 300;
	  if(type == "large shield") return 350;
	  if(type == "tower shield") return 550;

}

valid_type(type) {
	/*Bludgeons*/
  if(type == "club") return 1;
  if(type == "spiked club") return 1;
  if(type == "staff") return 1;
  if(type == "quarter staff") return 1;
  if(type == "mace") return 1;
  if(type == "morningstar") return 1;
  if(type == "hammer") return 1;
  if(type == "maul") return 1;
  if(type == "flail") return 1;
  if(type == "warhammer") return 1;
  /*Axes*/
    if(type == "hatchet") return 2;
    if(type == "hand axe") return 2;
    if(type == "head axe") return 2;
    if(type == "field axe") return 2;
    if(type == "bearded axe") return 2;
    if(type == "broad axe") return 2;
    if(type == "battle axe") return 2;
    if(type == "two-edged axe") return 2;
    if(type == "war axe") return 2;
    if(type == "great axe") return 2;
	/*Sword*/
  if(type == "dagger") return 3;
  if(type == "short sword") return 3;
  if(type == "sabre") return 3;
  if(type == "scimitar") return 3;
  if(type == "cutlass") return 3;
  if(type == "long sword") return 3;
  if(type == "broad sword") return 3;
  if(type == "claymore") return 3;
  if(type == "bastard sword") return 3;
  if(type == "greatsword") return 3;
  /*Shields*/
  if(type == "buckler") return 4;
  if(type == "small shield") return 4;
  if(type == "spiked shield") return 4;
  if(type == "knight shield") return 4;
  if(type == "medium shield") return 4;
  if(type == "kite shield") return 4;
  if(type == "large shield") return 4;
  if(type == "tower shield") return 4;
  /*Bows, en tiia miksi?*/
  if(type == "short bow") return 5;
  if(type == "composite bow") return 5;
  if(type == "long bow") return 5;
  if(type == "short war bow") return 5;
  if(type == "long war bow") return 5;
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
  /*Bludgeons*/
  dam_types += (["club":"100 0 0"]);
  dam_types += (["spiked club":"80 0 20"]);
  dam_types += (["staff":"100 0 0"]);
  dam_types += (["quarter staff":"100 0 0"]);
  dam_types += (["mace":"90 0 10"]);
  dam_types += (["morningstar":"80 0 20"]);
  dam_types += (["hammer":"80 0 20"]);
  dam_types += (["maul":"100 0 0"]);
  dam_types += (["flail":"70 0 30"]);
  dam_types += (["warhammer":"100 0 0"]);
  /*Axes*/
  dam_types += (["hatchet":"40 60 0"]);
  dam_types += (["hand axe":"40 60 0"]);
  dam_types += (["broad axe":"50 50 0"]);
  dam_types += (["battle axe":"40 40 20"]);
  dam_types += (["two-edged axe":"30 70 0"]);
  dam_types += (["great axe":"50 50 0"]);
  dam_types += (["bearded axe":"60 40 0"]);
  dam_types += (["head axe":"60 30 10"]);
  dam_types += (["field axe":"70 30 0"]);
  dam_types += (["war axe":"60 20 20"]);
  /*Swords*/
  dam_types += (["dagger":"0 10 90"]);
  dam_types += (["short sword":"0 50 50"]);
  dam_types += (["scimitar":"0 100 0"]);
  dam_types += (["long sword":"10 70 20"]);
  dam_types += (["claymore":"30 60 10"]);
  dam_types += (["broad sword":"30 70 0"]);
  dam_types += (["bastard sword":"20 80 0"]);
  dam_types += (["cutlass":"20 70 10"]);
  dam_types += (["greatsword":"40 60 0"]);
  dam_types += (["sabre":"20 70 10"]);

  /* hb [-2,2] , db [1,9]. */
  /* the weapon subtype classes are not comparable with each other */
  bonuses = ([ ]);
  bonuses += (["staff":"10 1"]);
  bonuses += (["quarter staff":"9 2"]);
  bonuses += (["club":"8 3"]);
  bonuses += (["spiked club":"7 4"]);
  bonuses += (["mace":"6 5"]);
  bonuses += (["hammer":"5 6"]);
  bonuses += (["warhammer":"4 7"]);
  bonuses += (["maul":"3 8"]);
  bonuses += (["morningstar":"2 9"]);
  bonuses += (["flail":"1 10"]);

  bonuses += (["hatchet":"10 2"]);
  bonuses += (["hand axe":"9 3"]);
  bonuses += (["broad axe":"8 4"]);
  bonuses += (["battle axe":"7 5"]);
  bonuses += (["two-edged axe":"6 6"]);
  bonuses += (["great axe":"5 7"]);
  bonuses += (["bearded axe":"4 8"]);
  bonuses += (["field axe":"3 9"]);
  bonuses += (["war axe":"2 10"]);

  bonuses += (["dagger":"10 1"]);
  bonuses += (["short sword":"9 2"]);
  bonuses += (["scimitar":"8 3"]);
  bonuses += (["long sword":"7 4"]);
  bonuses += (["claymore":"6 5"]);
  bonuses += (["broad sword":"5 6"]);
  bonuses += (["bastard sword":"4 7"]);
  bonuses += (["cutlass":"3 8"]);
  bonuses += (["greatsword":"2 9"]);
  bonuses += (["sabre":"1 10"]);

  bonuses += (["buckler" :"10 3"]);
  bonuses += (["spiked shield":"9 4"]);
  bonuses += (["small shield" :"8 5"]);
  bonuses += (["knight shield" :"7 6"]);
  bonuses += (["medium shield" :"6 7"]);
  bonuses += (["kite shield" :"5 8"]);
  bonuses += (["large shield" :"4 9"]);
  bonuses += (["tower shield" :"3 10"]);
}

get_long_desc(object weapon) {
  string type;
  type = weapon->query_sub_type();
  if(!valid_type(type)) return 0;
  switch(type) {
  /*Bludgeons*/
    case "club": return
  "Write new desc.\n";
    case "spiked club": return
  "Write new desc.\n";
  case "staff": return
"Write new desc.\n";
  case "quarter staff": return
"Write new desc.\n";
  case "mace": return
"The mace is a tool, an advanced version of a club. The haft is smooth,\n"+
"all rough spots have been worked away. It has a specified handle.\n"+
"Some metal reinforcements have been done to the end of the weapon,\n"+
"three spikes point out of the surface.\n";
  case "morningstar": return
"The morningstar is like it's bigger version, flail, but smaller.\n"+
"It is easier to use and it won't tear it's user if used inexperiencedly.\n"+
"It's prefered by many mounted warriors who like to use shield in their\n"+
"other hand. A small haft is attached to a chain that end to a spiked\n"+
"metal ball. The spikes are not very big and the ball is not as devastating\n"+
"as in a flail.\n";
  case "hammer": return
"Write new desc.\n";
  case "flail": return
"The flail is the most devastating weapon available. It is the choise of\n"+
"sadists and fanatics. A quite long haft is attached to a chain that end\n"+
"to a spiked metal ball. It is not used to simply kill somebody, but to\n"+
"pierce, bash and torn his flesh. If well used, it leaves behind nothing\n"+
"but mutilated slumps of flesh and bone.\n";
  case "warhammer": return
"The warhammer is made completely of metal alloy. A strong thick haft\n"+
"ends into a solid cube of cold metal. The krushing effect of this weapon is\n"+
"quite destructive. It's a good example of the new weapon craft.\n";
  case "maul": return
"The maul is a very simple weapon. A long haft is attached into a large\n"+
"cube of cold metal. No armour can protect the target from the utterly\n"+
"devastating effect of the horrible force when the maul is swung.\n"+
"While warhammer is used to hurt, this item is used to kill.\n";
/* Axes*/
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
  case "bearded axe": return
"Write new desc.\n";
  case "head axe": return
"Write new desc.\n";
  case "field axe": return
"Write new desc.\n";
  case "war axe": return
"Write new desc.\n";
/* Swords*/
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
  case "long sword": return
"The long sword is a basic sword. It's two-edged blade long and quite thin.";
  case "claymore": return
"The claymore is longer than a long sword and it's blade is thicker.";
  case "broad sword": return
"The broad sword is used by strong warriors. It's strong blade is meant to\n"+
"endure great force. The sword is the biggest and heaviest sword available.\n";
  case "bastard sword": return
"Write new desc.\n";
  case "cutlass": return
"Write new desc.\n";
  case "greatsword": return
"Write new desc.\n";
  case "sabre": return
"Write new desc.\n";
/* Shields*/

  case "buckler": return
"Write new desc.\n";
  case "spiked shield": return
"Write new desc.\n";
  case "small shield": return
"Write new desc.\n";
  case "large shield": return
"Write new desc.\n";
  case "medium shield": return
"Write new desc.\n";
  case "knight shield": return
"Write new desc.\n";
  case "kite shield": return
"Write new desc.\n";
  case "tower shield": return
"Write new desc.\n";
  }
}
