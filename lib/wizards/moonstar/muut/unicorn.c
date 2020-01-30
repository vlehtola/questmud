object liv;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
   tell_object(liv, "You are now an unicorn!\n");
   mina->update_stats();
}

end_unicorn() {
destruct(this_object());
}

short() {
        return "A beautiful unicorn called "+liv->query_name();
}

long()  {
      write("Iso paha poika joka juoksee ympari taloa. Muahahahahah.");
}

query_int() {
        return liv->query_int()+300;
}

query_con() {
        return liv->query_wis()+300;
}
query_dex() {
        return liv->query_con()+150;
}
