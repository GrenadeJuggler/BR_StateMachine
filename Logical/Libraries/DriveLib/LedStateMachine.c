
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif

void LedStateMachine(struct LedStateMachine* inst)
{
	switch(inst->state)
	{
		case ST_INIT:
			{
				break;
			}
		
		case ST_UNKNOWN:
			{
				//��� ����������� ��������� �������� (������������ ��� � ����������)
				if(inst->timer%5==0)
				{
					inst->led1=!inst->led1;
					inst->led2=!inst->led2;
					inst->led3=!inst->led3;
					inst->led4=!inst->led4;
				}
				break;
			}	
		
		case ST_CLOSE:
			{
				//��� �������� ��������� ��� �����
				//1111
				inst->led1=1;
				inst->led2=1;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case ST_NEG:
			{ 
				//0111
				inst->led1=0;
				if(inst->timer%10==0) //������������ ��� � �������
					inst->led2=!inst->led2;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case ST_ACC_NEG:
			{
				//0011
				inst->led1=0;
				inst->led2=0;
				if(inst->timer%5==0) //������������ ��� � ����������
					inst->led3=!inst->led3;
				inst->led4=1;
				break;
			}
		case ST_DEC_NEG:
			{
				//0001
				inst->led1=0;
				inst->led2=0;
				inst->led3=0;
				if(inst->timer%10==0)//������������ ��� � �������
					inst->led4=!inst->led4;
				break;
			}
		
		
		case ST_OPEN:
			{
				//��� �������� ��������� ��� ��������
				//0000
				inst->led1=0;
				inst->led2=0;
				inst->led3=0;
				inst->led4=0;
				break;
			}
		case ST_POS:
			{
				//0001
				inst->led1=0;
				inst->led2=0;
				if(inst->timer%10==0)//������������ ��� � �������
					inst->led3=!inst->led3;
				inst->led4=1;
				break;
			}
		case ST_ACC_POS:
			{
				//0011
				inst->led1=0;
				if(inst->timer%5==0) //������������ ��� � ����������
					inst->led2=!inst->led2;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case ST_DEC_POS:
			{
				//0111
				if(inst->timer%10==0)//������������ ��� � �������
					inst->led1=!inst->led1;
				inst->led2=1;
				inst->led3=1;
				inst->led4=1;
				break;
			}
	}
	//������ +1 ���
	inst->timer++;
}
