object liv;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
   tell_object(liv, "Helb! You are shadowed!\n");
}
self_destruct() {
destruct(this_object());
}

short() {
return "jepjep";
}

               
