object blue_player, red_player;
int attack, defence;
int ra = 1, rd = 1, ba = 1, bd = 1;
string tmp, tmp2;
int r = 0;
int red_hp = 0, blue_hp = 0;

string red_attack(string str) {
 tmp = "/wizards/rimber/test/colosseum/blue.c"->blue_player();
 blue_player = find_player(lower_case(tmp));
 tmp2 = "/wizards/rimber/test/colosseum/red.c"->red_player();
 red_player = find_player(lower_case(tmp2));
 if(ra == 1) {
  attack = "/wizards/rimber/test/colosseum/red.c"->attack1();
 }
 if(ra == 2) {
  attack = "/wizards/rimber/test/colosseum/red.c"->attack2();
 }
 if(ra == 3) {
  attack = "/wizards/rimber/test/colosseum/red.c"->attack3();
 }
 switch(attack) {
  case 1 : tell_object(red_player, "Your dragon draws deeps breath and exhales fire towards its oppponent.\n");
   tell_object(blue_player, "Red one's dragon draws breath and exhales fire towards your dragon.\n");
 ra++;
  break;
  case 2 : tell_object(red_player, "Your dragon turns around quickly and sweeps its tail towards its opponent.\n");
   tell_object(blue_player, "Red one's dragon turns around quickly and suddenly its tail sweeps towards\n your dragon.\n");
 ra++;
  break;
  case 3 : tell_object(red_player, "Your dragon rushes fiercly towards its opponent.\n");
   tell_object(blue_player, "Red one's dragon rushes towards your dragon.\n");
  ra++;
  break;
 }
}

string red_defence(string str) {
 tmp = "/wizards/rimber/test/colosseum/blue.c"->blue_player();
 blue_player = find_player(lower_case(tmp));
 tmp2 = "/wizards/rimber/test/colosseum/red.c"->red_player();
 red_player = find_player(lower_case(tmp2));
 if(rd == 1) {
  defence = "/wizards/rimber/test/colosseum/red.c"->defence1();
 }
 if(rd == 2) {
  defence = "/wizards/rimber/test/colosseum/red.c"->defence2();
 }
 if(rd == 3) {
  defence = "/wizards/rimber/test/colosseum/red.c"->defence3();
 }
 switch(defence) {
 case 1 :
if(attack == 3) {
 tell_object(red_player, "Your dragon tries to block firebreath but manage only to reduce it.\n");
 tell_object(blue_player, "Red one's dragon tries to block your dragons firebreath.\n");
 red_hp += 100;
 if(red_hp >= 500) {
 r = 7;
 }
}
if(attack == 2) {
 tell_object(red_player, "Your dragon tries to block but the tailsweep hits its legs causing much damage.\n");
 tell_object(blue_player, "And the red one's dragon uses wrong defence and is vulnerable your dragon's attack.\n");
 red_hp += 200;
 if(red_hp >= 500) {
 r = 7;
 }
}
if(attack == 1) {
 tell_object(red_player, "Your dragon blocks easily blue one's attack.\n");
 tell_object(blue_player, "but red one's dragon blocks it easily.\n");
}
rd++;
  break;
 case 2 :
if(attack == 1) {
 tell_object(red_player, "Your dragon tries to avoid firebreath but jumping but it makes it only vulnerable.\n");
 tell_object(blue_player, "The red one's dragon jumps but your dragon's firebreath catches it easily.\n");
 red_hp += 200;
 if(red_hp >= 500) {
 r = 7;
 }
}
if(attack == 2) {
 tell_object(red_player, "But your dragon jumps over the tail.\n");
 tell_object(blue_player, "But the red one's dragon avoids it completely by jumping over the tail.\n");
}
if(attack == 3) {
 tell_object(red_player, "Your dragon jumps but the blue one's dragon still hits it's legs..\n");
 tell_object(blue_player, "The red one's dragon jumps but manage only to reduce the damage.\n");
 red_hp += 100;
 if(red_hp >= 500) {
 r = 7;
 }
}
rd++;
 break;
 case 3 :
if(attack == 1) {
 tell_object(red_player, "Your dragon swifts quickly and avoids the blue one's firebreath.\n");
 tell_object(blue_player, "The red one's dragon swifts quickly and the firebreath misses it.\n");
}
if(attack == 2) {
 tell_object(red_player, "Your dragon swifts quickly but the tailsweep catches it and makes some damage.\n");
 tell_object(blue_player, "The red one's dragon tries to swift but your dragon's tailsweeps manage to make sama damage.\n");
 red_hp += 100;
 if(red_hp >= 500) {
 r = 7;
 }
}
if(attack == 3) {
 tell_object(red_player, "Your dragon tries to swift but has no escape from the blue one's bodyrush.\n");
 tell_object(blue_player, "And hits hard the red one's dragon.\n");
 red_hp += 200;
 if(red_hp >= 500) {
 r = 7;
 }
}
rd++;
 break;
 }
 "/wizards/rimber/test/colosseum/arena.c"->battle();
 r++;
 if(r == 7) { ra = 1, rd = 1, ba = 1, bd = 1, red_hp = 0, blue_hp = 0; }
}

string blue_attack(string str) {
 tmp = "/wizards/rimber/test/colosseum/blue.c"->blue_player();
 blue_player = find_player(lower_case(tmp));
 tmp2 = "/wizards/rimber/test/colosseum/red.c"->red_player();
 red_player = find_player(lower_case(tmp2));
  if(ba == 1) {
  attack = "/wizards/rimber/test/colosseum/red.c"->attack1();
 }
 if(ba == 2) {
  attack = "/wizards/rimber/test/colosseum/red.c"->attack2();
 }
 if(ba == 3) {
  attack = "/wizards/rimber/test/colosseum/red.c"->attack3();
 }
 switch(attack) {
  case 1 : tell_object(blue_player, "Your dragon draws deeps breath and exhales fire towards its oppponent.\n");
   tell_object(red_player, "The blue one's dragon draws breath and exhales fire towards your dragon.\n");
 ba++;
  break;
  case 2 : tell_object(blue_player, "Your dragon turns around quickly and sweeps its tail towards its opponent.\n");
   tell_object(red_player, "The blue one's dragon turns around quickly and suddenly its tail sweeps towards\n your dragon.\n");
 ba++;
  break;
  case 3 : tell_object(blue_player, "Your dragon rushes fiercly towards its opponent.\n");
   tell_object(red_player, "The blue one's dragon rushes towards your dragon.\n");
  ba++;
  break;
 }
}

string blue_defence(string str) {
 tmp = "/wizards/rimber/test/colosseum/blue.c"->blue_player();
 blue_player = find_player(lower_case(tmp));
 tmp2 = "/wizards/rimber/test/colosseum/red.c"->red_player();
 red_player = find_player(lower_case(tmp2));
 if(bd == 1) {
  defence = "/wizards/rimber/test/colosseum/blue.c"->defence1();
 }
 if(bd == 2) {
  defence = "/wizards/rimber/test/colosseum/blue.c"->defence2();
 }
 if(bd == 3) {
  defence = "/wizards/rimber/test/colosseum/blue.c"->defence3();
 }
 switch(defence) {
 case 1 :
if(attack == 1) {
 tell_object(blue_player, "Your dragon tries to block firebreath but manage only to reduce it.\n");
 tell_object(red_player, "The blue one's dragon tries to block your dragons firebreath.\n");
 blue_hp += 100;
 if(blue_hp >= 500) {
 r = 7;
 }
}
if(attack == 2) {
 tell_object(blue_player, "Your dragon tries to block but the tailsweep hits its legs causing much damage.\n");
 tell_object(red_player, "And the blue one's dragon uses wrong defence and is vulnerable your dragon's attack.\n");
 blue_hp += 200;
 if(blue_hp >= 500) {
 r = 7;
 }
}
if(attack == 3) {
 tell_object(blue_player, "Your dragon blocks easily the red one's attack.\n");
 tell_object(red_player, "But the blue one's dragon blocks it easily.\n");
}
bd++;
 break;
 case 2 :
if(attack == 1) {
 tell_object(blue_player, "Your dragon tries to avoid firebreath but jumping but it makes it only vulnerable.\n");
 tell_object(red_player, "The blue one's dragon jumps but your dragon's firebreath catches it easily.\n");
 blue_hp += 200;
 if(blue_hp >= 500) {
 r = 7;
 }
}
if(attack == 2) {
 tell_object(blue_player, "But your dragon jumps over the tail.\n");
 tell_object(red_player, "But the blue one's dragon avoids it completely by jumping over the tail.\n");
}
if(attack == 3) {
 tell_object(blue_player, "Your dragon jumps but the red one's dragon still hits it's legs..\n");
 tell_object(red_player, "The red one's dragon jumps but manage only to reduce the damage.\n");
 blue_hp += 100;
 if(blue_hp >= 500) {
 r = 7;
 }
}
bd++;
 break;
 case 3 :
if(attack == 1) {
 tell_object(blue_player, "Your dragon swifts quickly and avoids the red one's firebreath.\n");
 tell_object(red_player, "The blue one's dragon swifts quickly and the firebreath misses it.\n");
}
if(attack == 2) {
 tell_object(blue_player, "Your dragon swifts quickly but the tailsweep catches it and makes some damage.\n");
 tell_object(red_player, "The blue one's dragon tries to swift but your dragon's tailsweeps manage to make sama damage.\n");
 blue_hp += 100;
 if(blue_hp >= 500) {
 r = 7;
 }
}
if(attack == 3) {
 tell_object(blue_player, "Your dragon tries to swift but has no escape from the red one's bodyrush.\n");
 tell_object(red_player, "And hits hard the blue one's dragon.\n");
 blue_hp += 200;
 if(blue_hp >= 500) {
 r = 7;
 }
}
bd++;
 break;
 }
 "/wizards/rimber/test/colosseum/arena.c"->battle();
 r++;
 if(r == 7) { ra = 1, rd = 1, ba = 1, bd = 1, blue_hp = 0, red_hp = 0; }
}

int red_one() { return red_hp; }

int blue_one() { return blue_hp; }
