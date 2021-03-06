#include "Unit_Logging.h"

#ifdef _CPPUNIT_TEST

CUnit_Frame_Logging::~CUnit_Frame_Logging()
{

}

void CUnit_Frame_Logging::setUp(void)
{
    m_pFrameLoggingStrategy = new Frame_Logging_Strategy();
}

void CUnit_Frame_Logging::tearDown(void)
{
    SAFE_DELETE(m_pFrameLoggingStrategy);
}

void CUnit_Frame_Logging::Test_Debug_Log(void)
{
    //是否打开ACE_DEBUG文件存储
    Logging_Config_Param objParam;

    sprintf_safe(objParam.m_strLogFile, 256, "servertest.log");
    objParam.m_iChkInterval = 600;
    objParam.m_iLogFileMaxCnt = 3;
    objParam.m_iLogFileMaxSize = 10240;
    sprintf_safe(objParam.m_strLogLevel, 128, "INFO");

    m_pFrameLoggingStrategy->InitLogStrategy(objParam);

    m_pFrameLoggingStrategy->EndLogStrategy();

    ACE_DEBUG((LM_INFO, "[CUnit_Frame_Logging]Test_Debug_Log ok.\n"));
}

#endif


