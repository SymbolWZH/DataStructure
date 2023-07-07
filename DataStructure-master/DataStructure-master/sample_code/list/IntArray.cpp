/*
 * summer.cpp
 *
 *  Created on: 2018��1��23��
 *      Author: Administrator
 */

#include "IntArray.h"

IntArray::IntArray(int len) {
    m_length = len;
}

bool IntArray::construct() {   //�ڶ��׶ι���
    bool ret = true;

    m_pointer = new int[m_length]; //�ڵڶ��׶ι���������ϵͳ��Դ

    if (m_pointer) {
        for (int i = 0; i < m_length; i++) {
            m_pointer[i] = 0;
        }
    } else {
        ret = false;
    }

    return ret;
}

IntArray* IntArray::NewInstance(int length) {
    IntArray* ret = new IntArray(length);

    if (!(ret && ret->construct())) {    //�ھ�̬��Ա�����е��ö��׹��캯��
        delete ret;              //�������ϵͳ��Դʧ����ô�����ʧ���ˣ�Ҫɾ��֮ǰ�����Ķ���
        ret = 0;
    }

    return ret;
}

int IntArray::length() {
    return m_length;
}

bool IntArray::get(int index, int& value) {
    bool ret = (0 <= index) && (index < length());

    if (ret) {
        value = m_pointer[index];
    }

    return ret;
}

bool IntArray::set(int index, int value) {
    bool ret = (0 <= index) && (index < length());

    if (ret) {
        m_pointer[index] = value;
    }

    return ret;
}

IntArray::~IntArray() {
    delete[] m_pointer;
}




