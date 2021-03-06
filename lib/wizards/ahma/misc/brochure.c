reset(arg) {
  if(arg) return;
}

short() {
  return "A small, wrinkled brochure";
}

id(str) {
  return str == "brochure";
}

query_no_save() {
  return 1;
}

long() {
  write(" `穈捶,反,穈穈捶,反,穈穈捶,反,穈穈捶,反,穈穈捶,反,穈穈捶,反,穈穈捶,反,穈穈捶,反,�,.反,\n" +
        " �,                             QUESTMUD - MUDCON                                    |\n" +
        " `                                                                                   穃n" +
        " ,` Lauantaiksi 9.3.2002 on varattu otaniemen rantasauna (espoossa). Tapahtuma      �,\n" +
        " �  alkaa illalla noin klo 18. Paikalta poistutaan viimeist滗n klo 7:00 seuraavana  ,碶n" +
        "`   aamuna. Itse sauna on l鋗min aina klo 03 asti.                                 穈\n" +
        "捶                                                                                 �,\n" +
        ",�  Kaikki questmudin pelaajat ja wizardit ovat tervetulleita. Paikan vuokra        , \n" +
        "�,  kustannetaan mudin puolesta, joten tilaisuus on kaikille ilmainen.             �,\n" +
        " �, Ottakaa mukaan juomia ja sy鰐鋠滗. K鋣t鰏s� on iso j滗kaappi ja mikro.         `\n" +
        " ,�                                                                               穈\n" +
        " �  Koska tapahtuma on sis鋞iloissa, k鋣tt鋣dymme sen mukaan. Hauskaa saa pit滗,  `穃n" +
        "`,  tyhmyyksi� ei sallita.                                                        ,碶n" +
        "�                                                                                 ,穃n" +
        ",`  Tapahtumaan ilmottautuminen tapahtuu tavernassa (e from inn),                 ,\n" +
        " `, jos osaanottajia ei ole tarpeeksi, homma perutaan.                             `\n" +
        ",`                                                                                ,碶n" +
        " |  //Celtron                                                                    ,穃n" +
        " |                                                                              `,\n" +
        " `捶,`�.``�,反�,`�.``�,反�,`�.``�,反�,`�.``�,反�,`�.``�,反�,`�.``�,反�,`�.``�,反穃n");
}

get() {
  return 1;
}

query_weight() {
  return 1;
}

init() {
  add_action("drop", "drop");
}

drop(str) {
  call_out("checkplr", 2);
  return;
}

checkplr() {
  if(environment(this_object())->query_name()) return 1;
  tell_room(environment(this_object()), "The brochure fades away as it touches the ground.\n");
  destruct(this_object());
}  
