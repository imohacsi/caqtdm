/*
 *  This file is part of the caQtDM Framework, developed at the Paul Scherrer Institut,
 *  Villigen, Switzerland
 *
 *  The caQtDM Framework is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The caQtDM Framework is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the caQtDM Framework.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright (c) 2010 - 2014
 *
 *  Author:
 *    Anton Mezger
 *  Contact details:
 *    anton.mezger@psi.ch
 */

#if defined(_MSC_VER)
#define NOMINMAX
#include <windows.h>
#define QWT_DLL
#endif

#include "cameter.h"

#if defined(_MSC_VER)
#define fmax max
#define fmin min
#endif

#if QWT_VERSION < 0x060100

class myDialScaleDraw: public QwtDialScaleDraw
{
public:
    myDialScaleDraw(caMeter *w) : QwtDialScaleDraw(w)
    {
        thisParent = w;
    }
    virtual QwtText label(double v) const
    {
        return QwtText(thisParent->setLabel(v,""));
    }

private:

    caMeter *thisParent;

};
#else
class myDialScaleDraw: public QwtRoundScaleDraw
{
public:
    explicit myDialScaleDraw(caMeter *w) {
        thisParent = w;
    }

    virtual QwtText label(double v) const
    {
        return QwtText(thisParent->setLabel(v,""));
    }

private:
    caMeter *thisParent;
};
#endif

caMeter::~caMeter() {
}

caMeter::caMeter(QWidget *parent) : QwtDial(parent)
{

    thisBaseColor = QColor( Qt::gray);   
    thisScaleColor = thisBaseColor.dark( 200 ).light( 800 );
    setScaleDefaultColor(true);

#if QWT_VERSION < 0x060100
    QwtDialScaleDraw *ScaleDraw = new myDialScaleDraw(this);
    setScaleDraw((QwtDialScaleDraw*) ScaleDraw);
#else
    myDialScaleDraw *ScaleDraw = new myDialScaleDraw(this);
    setScaleDraw(ScaleDraw);
#endif

    setWrapping(false);
    setReadOnly(true);
    setFocusPolicy(Qt::NoFocus);
    setPalette( colorTheme(thisBaseColor.dark( 150 ) ) );

    setOrigin(135.0);
    setScaleArc(0.0, 270.0);

    ScaleDraw->setPenWidth(1);
    setLineWidth(1);
    setFrameShadow(QwtDial::Sunken);

    ScaleDraw->setTickLength( QwtScaleDiv::MajorTick, 6);
    ScaleDraw->setSpacing(3.0);

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow, true, Qt::red, QColor(Qt::gray).light(130));
    setNeedle(needle);

    setColorMode(Static);
    setMinValue(0.0);
    setMaxValue(300.0);
    setScaleEnabled(true);
    setValueDisplayed(true);
    setUnitsEnabled(true);
    setPrecision(0);
    setPrecisionMode(Channel);
    setFormatType(decimal);
    setLimitsMode(Channel);

#if QWT_VERSION < 0x060100
    setScaleComponents(QwtAbstractScaleDraw::Ticks | QwtAbstractScaleDraw::Labels);
    setScaleTicks(0, 4, 8);
    setRange(thisMinValue, thisMaxValue);
    setScale(-1, 2, (thisMaxValue-thisMinValue)/10.0);  //maxMajIntv: Maximum major interval, maxMinIntv: Maximum minor interval
#else
    setScale( thisMinValue, thisMaxValue);
    setScaleStepSize((thisMinValue - thisMaxValue)/10.0);
#endif
    thisLabel = "V";
}

void caMeter::setMinValue(double v) {
    thisMinValue = v;
#if QWT_VERSION < 0x060100
    setRange(thisMinValue, thisMaxValue);
    setScale(-1, 2, (thisMinValue - thisMaxValue)/10.0);
#else
    setScale( thisMinValue, thisMaxValue);
    setScaleStepSize((thisMinValue - thisMaxValue)/10.0);
#endif
}

void caMeter::setMaxValue(double v) {
    thisMaxValue = v;
#if QWT_VERSION < 0x060100
    setRange(thisMinValue, thisMaxValue);
    setScale(-1, 2, (thisMinValue - thisMaxValue)/10.0);
#else
    setScale( thisMinValue, thisMaxValue);
     setScaleStepSize((thisMinValue - thisMaxValue)/10.0);
#endif
    update();
}

void caMeter::drawScaleContents(QPainter *painter, const QPointF &center, double radius) const
{
    QRectF rect( 2./10.*width(), 0.0, 6.0/10.0*width(), 9.0/10.0*height());

    const QColor color = palette().color(QPalette::Text);
    painter->setPen(color);

    const int flags = Qt::AlignBottom | Qt::AlignHCenter;
    QFont f;

    f.setPointSizeF(80.0);
    QRect fontBoundRect = painter->fontMetrics().boundingRect(rect.toRect(),flags, thisLabel);
    while(rect.width() < (fontBoundRect.width()) || rect.height() < (fontBoundRect.height())) {
        if(f.pointSizeF() < 3) break;
        f.setPointSizeF(f.pointSizeF()*0.95);
        painter->setFont(f);
        fontBoundRect = painter->fontMetrics().boundingRect(rect.toRect(),flags, thisLabel);
    }

    painter->setBrush(QColor(0,0,0,0));
    painter->setPen(QColor(0,0,0,0));
    //painter->setBrush(Qt::gray);
    //painter->setPen(Qt::gray);

    painter->drawRect(rect);

    if(thisScaleDefaultColor) {
       painter->setPen(thisBaseColor.dark( 200 ).light( 800 ));
    } else {
       painter->setPen(thisScaleColor);
    }
    painter->drawText(fontBoundRect, Qt::AlignHCenter , thisLabel);

}

void caMeter::setFormat(int prec)
{
    int precision = prec;
    if(precision > 17) precision = 17;
    if(thisPrecMode == User) {
        precision = getPrecision();
    }
    switch (thisFormatType) {
    case decimal:
        if(precision >= 0) {
           sprintf(thisFormat, "%s.%dlf", "%", precision);
        } else {
           sprintf(thisFormat, "%s.%dle", "%", -precision);
        }
        break;
    case compact:
        sprintf(thisFormat, "%s.%dle", "%", qAbs(precision));
        sprintf(thisFormatC, "%s.%dlf", "%", qAbs(precision));
        break;
    case exponential:
    case engr_notation:
        sprintf(thisFormat, "%s.%dle", "%", qAbs(precision));
        break;
    case truncated:
        strcpy(thisFormat, "%d");
        break;
    default:
        sprintf(thisFormat, "%s.%dlf", "%", precision);
    }
}

QString caMeter::setLabel(double value, const QString& units)
{
    char asc[1024];
    QString label;

    if(thisFormatType == compact) {
      if ((value < 1.e4 && value > 1.e-4) || (value > -1.e4 && value < -1.e-4) || value == 0.0) {
        sprintf(asc, thisFormatC, value);
      } else {
        sprintf(asc, thisFormat, value);
      }
    } else if(thisFormatType == truncated) {
        sprintf(asc, thisFormat, (int) value);
    } else {
        sprintf(asc, thisFormat, value);
    }
    if(thisUnitMode) {
        strcat(asc, " ");
        strcat(asc, units.toAscii().constData());
    }

    label = QString::fromAscii(asc);

    return label;
}

void caMeter::updateMeter()
{
    setValueUnits(lastValue, lastUnits);
}

void caMeter::setValueUnits(double value, const QString &units)
{
    setValue(value);
    thisLabel = setLabel(value, units);
    lastValue = value;
    lastUnits = units;
}

QPalette caMeter::colorTheme( const QColor &base ) const
{
    QPalette palette;
    palette.setColor( QPalette::Base, base );
    palette.setColor( QPalette::Window, base.dark( 150 ) );
    palette.setColor( QPalette::Mid, base.dark( 110 ) );
    palette.setColor( QPalette::Light, base.light( 170 ) );
    palette.setColor( QPalette::Dark, base.dark( 170 ) );
    if(thisScaleDefaultColor) {
       palette.setColor( QPalette::Text, base.dark( 200 ).light( 800 ) );
    } else {
       palette.setColor( QPalette::Text, thisScaleColor );
    }
    palette.setColor( QPalette::WindowText, base.dark( 200 ) );
    return palette;
}

void caMeter::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    int Width = width();
    QFont f = font();
    float size = Width/25.0;
    if(size < 3.0) size = 3.0;
    f.setPointSizeF(size);

    setFont(f);
    update();

}

void caMeter::invalidate()
{
#if QWT_VERSION >= 0x060100
    invalidateCache();
    setScale(getMinValue()-1, getMaxValue()+1);
    setScale(getMinValue(), getMaxValue());
#endif
}

void caMeter::setNormalColors()
{
    setAlarmColors(NO_ALARM);
}

void caMeter::setAlarmColors(short status)
{
    QColor c;

    switch (status) {

    case NO_ALARM:
        c=AL_GREEN;
        if(thisColorMode == Static) c= thisBaseColor.dark( 150 );
        break;
    case MINOR_ALARM:
        c=AL_YELLOW;
        if(thisColorMode == Static) c= thisBaseColor.dark( 150 );
        break;
    case MAJOR_ALARM:
        c=AL_RED;
        if(thisColorMode == Static) c= thisBaseColor.dark( 150 );
        break;
    case INVALID_ALARM:
        c=AL_WHITE;
        if(thisColorMode == Static) c= thisBaseColor.dark( 150 );
        break;
    case NOTCONNECTED:
        c=AL_WHITE;
        break;
    default:
        c= thisBaseColor.dark( 150 );
        break;
    }

    if((prevColor != c) || (thisScaleDefaultColor != prevScaleDefaultColor) || (thisScaleColor != prevScaleColor)){
      prevColor = c;
      prevScaleDefaultColor = thisScaleDefaultColor;
      prevScaleColor = thisScaleColor;
      setPalette( colorTheme( c) );
    }

}
