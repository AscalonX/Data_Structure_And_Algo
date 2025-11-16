void replace(const T& x, CP::list<T>& y) {
  auto it = begin();

  while(it != end()){
    if(*it == x){
      auto insertor = it;
      for(auto &xo : y){
        insert(insertor,xo);
      }

      it = erase(it);
    }
    else{
      ++it;
    }
  }
}
