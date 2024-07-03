#include "tess_ocr.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "../core/helpfunc.h"
#include "../core/opEnv.h"
tess_ocr::tess_ocr(): m_api(nullptr)   {
    init();
}
tess_ocr::~tess_ocr() {
    release();
}
int tess_ocr::init() {
    // ����Tesseract OCR����
    m_api = new tesseract::TessBaseAPI();
    // ��ʼ��Tesseract OCR
    if (m_api->Init(_ws2string( opEnv::getBasePath()+L"/tess_model").c_str(), "chi_sim")) {
        setlog("Could not initialize tesseract.\n");
        release();
    }
    return 0;
}
int tess_ocr::release() {
    if (m_api) {
        // ɾ��Tesseract OCR����
        delete m_api;
    }
    m_api = nullptr;
    return 0;
}

static string utf8_to_ansi(string strUTF8);

int tess_ocr::ocr(byte* data, int w, int h, int bpp, vocr_rec_t& result) {
    result.clear();
    if (m_api == nullptr)return -1;
    
    // ��ͼ���������ø�Tesseract OCR
    m_api->SetImage(data, w, h, bpp, w * bpp);

    // ִ������ʶ��
    m_api->Recognize(0);

    // ��ȡ���������
    tesseract::ResultIterator* ri = m_api->GetIterator();
    tesseract::PageIteratorLevel level = tesseract::RIL_WORD;
    //std::setlocale()
    // ��������������Ч����ѭ��
    if (ri != 0) {
        do {
            // ��ȡʶ����ĵ��ʺ����Ŷ�
            const char* word = ri->GetUTF8Text(level);
            int x1, x2, y1, y2;
            ri->BoundingBox(level, &x1, &y1, &x2, &y2);
            float conf = ri->Confidence(level);

            // ��ʾ���ʺ����Ŷ�
            //printf("word: '%s';  \tconf: %.2f box=[%d,%d %d,%d]; \n", word, conf, x1, y1, x2, y2);
            //std::wcout << L"xxx:" << utf82ws(word) << std::endl;
            ocr_rec_t ts;
            ts.confidence = conf;
            ts.left_top = point_t(x1, y1);
            ts.right_bottom = point_t(x2, y2);
            ts.text = _s2wstring(utf8_to_ansi(word));
            result.push_back(ts);
            // �ͷŵ��ʵ��ڴ�
            delete[] word;
        } while (ri->Next(level));
    }
    //Pix* px = m_api->GetInputImage();
    //pixWrite("test_oux.bmp", px, IFF_BMP);
    return result.size();
}

string utf8_to_ansi(string strUTF8) {
    UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8.c_str(), -1, NULL, NULL);
    WCHAR* wszBuffer = new WCHAR[nLen + 1];
    nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8.c_str(), -1, wszBuffer, nLen);
    wszBuffer[nLen] = 0;
    nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
    CHAR* szBuffer = new CHAR[nLen + 1];
    nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
    szBuffer[nLen] = 0;
    strUTF8 = szBuffer;
    delete[]szBuffer;
    delete[]wszBuffer;
    return strUTF8;
}