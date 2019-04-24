#pragma once

class SupportADessin;

class Dessinable {
 public:
  Dessinable(SupportADessin* support)
    : support(support)
  {}
  virtual ~Dessinable() {}
  virtual void dessine() = 0;

 protected:
  SupportADessin* support;
};
