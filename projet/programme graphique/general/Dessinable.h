#pragma once

class SupportADessin;

class Dessinable {
 public:
  Dessinable(SupportADessin* support)
    : support(support)
  {}
  virtual ~Dessinable() {}
  virtual void dessine() = 0;
  void change_support(SupportADessin* nouveau) {support=nouveau;}

 protected:
  SupportADessin* support;
};
