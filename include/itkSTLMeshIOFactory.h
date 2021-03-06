/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkSTLMeshIOFactory_h
#define itkSTLMeshIOFactory_h

#include "IOSTLExport.h"

#include "itkObjectFactoryBase.h"
#include "itkMeshIOBase.h"

namespace itk
{
/** \class STLMeshIOFactory
  * \brief Create instances of STLMeshIO objects using an object factory.
  *
  * \ingroup IOSTL
  */
class IOSTL_EXPORT STLMeshIOFactory:public ObjectFactoryBase
{
public:
  /** Standard class type alias. */
  using Self = STLMeshIOFactory;
  using Superclass = ObjectFactoryBase;
  using Pointer = SmartPointer< Self >;
  using ConstPointer = SmartPointer< const Self >;

  /** Class methods used to interface with the registered factories. */
  const char * GetITKSourceVersion(void) const override;

  const char * GetDescription(void) const override;

  /** Method for class instantiation. */
  itkFactorylessNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(STLMeshIOFactory, ObjectFactoryBase);

  /** Register one factory of this type  */
  static void RegisterOneFactory(void)
    {
    STLMeshIOFactory::Pointer vtkFactory = STLMeshIOFactory::New();

    ObjectFactoryBase::RegisterFactory(vtkFactory);
    }

protected:
  STLMeshIOFactory();
  ~STLMeshIOFactory() override;

  void PrintSelf(std::ostream & os, Indent indent) const override;

private:
  ITK_DISALLOW_COPY_AND_ASSIGN(STLMeshIOFactory);
};
} // end namespace itk

#endif
