#pragma once

#include "visObject.h"

class MObligEnOppgTo : public visObject { 
   public:
	   MObligEnOppgTo();
	   ~MObligEnOppgTo();

	   void init(int inMatrixUniform) override;
	   void draw() override;
};

