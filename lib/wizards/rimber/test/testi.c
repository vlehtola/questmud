void Strength(object drg) {
 int vakio = 60;
float multiplyer = 1.3;
 tell_room(environment(drg), "Small Black: \t");
 for(int i = 1;i < 21; i++) { tell_room(environment(drg), (vakio * (1+ (((i * multiplyer)/20) * 1))) + " "); }
 tell_room(environment(drg), "\nA Black: \t");
 for(int i = 1;i < 21; i++) { tell_room(environment(drg), (vakio * (1+ (((i * multiplyer)/20) * 2))) + " "); }
 tell_room(environment(drg), "\nLarge Black: \t");
 for(int i = 1;i < 21; i++) { tell_room(environment(drg), (vakio * (1+ (((i * multiplyer)/20) * 3))) + " "); }
 tell_room(environment(drg), "\nEnormous Black: ");
 for(int i = 1;i < 21; i++) { tell_room(environment(drg), (vakio * (1+ (((i * multiplyer)/20) * 4))) + " "); }
 tell_room(environment(drg), "\n");
}

GetStats(int lvl, string type, string stat) {
 int tmp, taso;
 int vakio = 35;
 float multiplyer;
 switch(type) {
  case "red" : switch(stat) {
		case "str" : multiplyer = 1.32; break;
		case "dex" : multiplyer = 1.18; break;
		case "con" : multiplyer = 1.22; break;
		case "wis" : multiplyer = 1.2; break;
		case "int" : multiplyer = 1.1; break;
               }
      break;
  case "blue" : switch(stat) {
		 case "str" : multiplyer = 1.23; break;
		 case "dex" : multiplyer = 1.3; break;
		 case "con" : multiplyer = 1.12; break;
		 case "wis" : multiplyer = 1.2; break;
		 case "int" : multiplyer = 1.25; break;
                }
      break;
  case "black" : switch(stat) {
		  case "str" : multiplyer = 1.24; break;
		  case "dex" : multiplyer = 1.1; break;
		  case "con" : multiplyer = 1.31; break;
		  case "wis" : multiplyer = 1.25; break;
		  case "int" : multiplyer = 1.22; break;
                 }
      break;
  case "white" : switch(stat) {
		  case "str" : multiplyer = 1.15; break;
		  case "dex" : multiplyer = 1.24; break;
		  case "con" : multiplyer = 1.18; break;
		  case "wis" : multiplyer = 1.3; break;
		  case "int" : multiplyer = 1.22; break;
                 }
      break;
  case "green" : switch(stat) {
		  case "str" : multiplyer = 1.19; break;
		  case "dex" : multiplyer = 1.22; break;
		  case "con" : multiplyer = 1.23; break;
		  case "wis" : multiplyer = 1.16; break;
		  case "int" : multiplyer = 1.33; break;
                 }
      break;
 }
 if(lvl < 21) taso = 1;
 if((lvl > 20) && (lvl < 41)) {
  taso = 2;
  lvl = lvl - 20;
 }
 if((lvl > 40) && (lvl < 61)) {
  taso = 3;
  lvl = lvl - 40;
 }
 if((lvl > 60) && (lvl < 81)) {
  taso = 4;
  lvl = lvl - 60;
 }
 tmp = vakio * (1+ (((lvl * multiplyer)/20) * taso));
 tmp = to_int(tmp);
 return tmp;
}
