inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if(arg) { return; }
switch(a) {
case 0:
set_short("vanhus deer");
set_level(80+random(5));
break;
case 1:
set_short("isohko deeri");
set_level(80+random(2));
break;
case 2:
set short("ihan pikkunen deeri");
set_level(75+random(20));
break;
}
set_name("deer");
set_alt_name("deeri");
set_aggressive(0);
set_long(
"Tama poro on aika iso ja silla on nelja jalkaa ja aika hassu otus on.\n"
);
set_gender(0);
}

case 1 : set_level(20+random(3));
