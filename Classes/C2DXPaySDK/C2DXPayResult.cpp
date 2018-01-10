#include "C2DXPayResult.h"


using namespace mob::paysdk;

C2DXPayResult::C2DXPayResult()
{
    payStatus = PAYRESULT_ERROR;
}

void C2DXPayResult::setPayStatus(int status)
{
    payStatus = status;
}

int C2DXPayResult::getPayStatus()
{
    return payStatus;
}

C2DXPayResult::~C2DXPayResult()
{

}