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
  write(" `·`´·,·´,·`·`´·,·´,·`·`´·,·´,·`·`´·,·´,·`·`´·,·´,·`·`´·,·´,·`·`´·,·´,·`·`´·,·´,·,.·´,\n" +
        " ´,                             QUESTMUD - MUDCON                                    |\n" +
        " `                                                                                   ·\n" +
        " ,` Lauantaiksi 9.3.2002 on varattu otaniemen rantasauna (espoossa). Tapahtuma      ´,\n" +
        " ·  alkaa illalla noin klo 18. Paikalta poistutaan viimeistään klo 7:00 seuraavana  ,´\n" +
        "`   aamuna. Itse sauna on lämmin aina klo 03 asti.                                 ·`\n" +
        "´·                                                                                 ·,\n" +
        ",´  Kaikki questmudin pelaajat ja wizardit ovat tervetulleita. Paikan vuokra        , \n" +
        "·,  kustannetaan mudin puolesta, joten tilaisuus on kaikille ilmainen.             ´,\n" +
        " ´, Ottakaa mukaan juomia ja syötävää. Käytössä on iso jääkaappi ja mikro.         `\n" +
        " ,´                                                                               ·`\n" +
        " ·  Koska tapahtuma on sisätiloissa, käyttäydymme sen mukaan. Hauskaa saa pitää,  `·\n" +
        "`,  tyhmyyksiä ei sallita.                                                        ,´\n" +
        "·                                                                                 ,·\n" +
        ",`  Tapahtumaan ilmottautuminen tapahtuu tavernassa (e from inn),                 ,\n" +
        " `, jos osaanottajia ei ole tarpeeksi, homma perutaan.                             `\n" +
        ",`                                                                                ,´\n" +
        " |  //Celtron                                                                    ,·\n" +
        " |                                                                              `,\n" +
        " `´·,`·.``·,·´·,`·.``·,·´·,`·.``·,·´·,`·.``·,·´·,`·.``·,·´·,`·.``·,·´·,`·.``·,·´·\n");
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
